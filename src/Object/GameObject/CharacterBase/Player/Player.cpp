#include "Player.h"



void Player::UpdateLeap()
{
	hand_exist_count = (LeapController::Get().IsHandExist()) ?
		std::min(1.0f, hand_exist_count + TimeManager::Get().GetDeltaTime() / hand_exist_take_time) :
		0.0f;

	hand_pos_by_ratio = LeapController::Get().GetHandCenterPosByRatio();

	if (!TimeManager::Get().IsIntervalTime(interval_time))
		return;

	prev_hand_pos = LeapController::Get().GetHandCenterPos();
	prev_hand_pos_by_ratio = LeapController::Get().GetHandCenterPosByRatio();
	prev_hand_normal = LeapController::Get().GetHandNormal();
}

void Player::ChangeMovePos()
{
	ci::Vec2f end_move_pos_ =
		ci::Vec2f(move_range.x * hand_pos_by_ratio.x,
			move_range.y * hand_pos_by_ratio.y);

	if (end_move_pos == end_move_pos_)
		return;

	IsMove(end_move_pos_);
}

bool Player::StartDelay()
{
	start_delay_time = std::fminf(1.0f, start_delay_time + TimeManager::Get().GetDeltaTime() / start_delay_take_time);
	if (start_delay_time < 1.0f)
		return false;
	if (hand_exist_count < 1.0f)
		return false;

	return true;
}

void Player::HandNormalRotation()
{
	// LeapMotion �� hand ��F�����Ă��Ȃ��Ƃ��͂���
	if (!LeapController::Get().IsHandExist())
		return;

	// ���̖@�����^������z������ [�|�S�T�x��菬����]�A[�S�T�x���傫���ꍇ] �͂���
	if (LeapController::Get().GetHandNormal().z > max_hand_normal_z_range ||
		LeapController::Get().GetHandNormal().z < min_hand_normal_z_range)
		return;

	float start_theta = std::atan2(prev_hand_normal.x - 0.0f, prev_hand_normal.y - (-1.0f));

	// 8frame�O�̖@����-60~60�ȓ��ɂȂ��Ȃ�͂���
	if (start_theta < min_hand_normal_xy_range &&
		start_theta > max_hand_normal_xy_range)
		return;

	// 6frame�O�̖@���ƍ����݂̖@���Ƃ̓���
	float dot_product = std::abs((prev_hand_normal.x * LeapController::Get().GetHandNormal().x) + (prev_hand_normal.y * LeapController::Get().GetHandNormal().y));

	// 6frame�O�̎�̖@���ƍ��̖@���Ƃ̓��ς� [�O�ȏ�`�T�S�x����] �̏ꍇ�͂���
	if (dot_product <= min_dot_product_range && dot_product > max_dot_product_range)
		return;

	// 6frame�O�̖@���ƍ��̖@���Ƃ̊p�x
	float theta = std::atan2(LeapController::Get().GetHandNormal().x - prev_hand_normal.x, LeapController::Get().GetHandNormal().y - prev_hand_normal.y);

	// |a| * |b|
	/*float vec_a_to_b = std::sqrtf((prev_hand_normal.x * prev_hand_normal.x) + (prev_hand_normal.y * prev_hand_normal.y)) *
	std::sqrtf((LeapController::Get().GetHandNormal().x * LeapController::Get().GetHandNormal().x) + (LeapController::Get().GetHandNormal().y * LeapController::Get().GetHandNormal().y));*/

	// �O�ό��� |a| * |b| * sin��
	//float cross_product = vec_a_to_b * std::sin(theta);

	// ���[���������
	ci::Vec2f distance_vec_normal = hand_pos_by_ratio - prev_hand_pos_by_ratio;

	// �Ƃ�܃m�[�}���C�Y
	(distance_vec_normal).normalize();

	IsRoll(distance_vec_normal * 4.0f);
}

void Player::HandPosZDistance()
{
	float distance = LeapController::Get().GetHandCenterPos().z - prev_hand_pos.z;

	// ���z���ɑ΂��Ă̈ړ��ʂ������Ȃ������ꍇ�͂���
	if (distance < dash_range)
		return;

	ci::Vec3f hand_distance = prev_hand_pos - LeapController::Get().GetHandCenterPos();
	distance = std::sqrtf((hand_distance.x * hand_distance.x) +
		(hand_distance.y * hand_distance.y) +
		(hand_distance.z * hand_distance.z));

	if (distance < dash_range * 2.0f)
		return;

	ci::Vec2f attack_move_pos = prev_hand_pos.xy() - LeapController::Get().GetHandCenterPos().xy();
	(attack_move_pos).normalize();

	IsAttack();
}

void Player::CollisionPlayerToCourse()
{
	ci::Vec2f player_pos = transform.position.xy();
	if (player_pos.lengthSquared() < course_rad * course_rad)
		return;

	player_pos.normalize();
	player_pos *= course_rad;
	transform.position.x = player_pos.x;
	transform.position.y = player_pos.y;
}

Player::Player()
{

}

Player::~Player()
{

}

void Player::Setup()
{

}

void Player::Setup(const float & hand_exist_take_time_,
	const float & interval_time_,
	const ci::Vec2f & move_range_,
	const float & start_delay_take_time_,
	const float & course_rad_,
	const float & min_hand_normal_z_range_,
	const float & max_hand_normal_z_range_,
	const float & min_hand_normal_xy_range_,
	const float & max_hand_normal_xy_range_,
	const float & min_dot_product_range_,
	const float & max_dot_product_range_,
	const float & dash_range_)
{
	hand_exist_count = 0.0f;
	hand_exist_take_time = hand_exist_take_time_;
	hand_pos_by_ratio = ci::Vec2f::zero();
	interval_time = interval_time_;
	prev_hand_pos = ci::Vec3f::zero();
	prev_hand_pos_by_ratio = ci::Vec2f::zero();
	prev_hand_normal = ci::Vec3f::zero();
	move_range = move_range_;
	start_delay_time = 0.0f;
	start_delay_take_time = start_delay_take_time_;
	course_rad = course_rad_;
	min_hand_normal_z_range = min_hand_normal_z_range_;
	max_hand_normal_z_range = max_hand_normal_z_range_;
	min_hand_normal_xy_range = min_hand_normal_xy_range_;
	max_hand_normal_xy_range = max_hand_normal_xy_range_;
	min_dot_product_range = min_dot_product_range_;
	max_dot_product_range = max_dot_product_range_;
	dash_range = dash_range_;
}

void Player::Update()
{
	// LeapMotion�̓���
	UpdateLeap();
	ChangeMovePos();
	if (StartDelay())
	{
		//HandNormalRotation();
		HandPosZDistance();
	}

	// �X�e�[�^�X�̍X�V
	UpdateStatus();

	// player�̈ړ��͈͂̐���
	CollisionPlayerToCourse();

	// Transform : matrix���X�e�[�W�̍s��ɕϊ�
	// yet

	UpdateMatrix();
}

void Player::Draw()
{
	ci::gl::pushModelView();

	ci::gl::multModelView(stage_matrix);
	// �`�ʈʒu�̒���
	ci::Matrix44f mtranslate = ci::Matrix44f::createTranslation(ci::Vec3f(0.0f, 1.0f, 0.0f));
	ci::gl::multModelView(mtranslate);
	ci::Matrix44f mrotate = ci::Matrix44f::createRotation(transform.angle);
	ci::gl::multModelView(mrotate);
	mtranslate = ci::Matrix44f::createTranslation(ci::Vec3f(0.0f, -1.0f, 0.0f));
	ci::gl::multModelView(mtranslate);
	ci::Matrix44f mscale = ci::Matrix44f::createScale(transform.scale);
	ci::gl::multModelView(mscale);
	mtranslate = ci::Matrix44f::createTranslation(ci::Vec3f(0.0f, 0.0f, -1.0f));
	ci::gl::multModelView(mtranslate);

	// model��draw
	// yet

	ci::gl::popModelView();
}
