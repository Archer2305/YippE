#include "main.h"
#include "pros/rtos.h"

using namespace okapi::literals;

pros::ADIDigitalOut band ('H');

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
    ADIButton limSwitch('C', false);

    motors_init();  //

	//pros::lcd::set_text(1, std::to_string(sizeof(double)));
	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {
    okapi::OdomState zero_state = {
            .x = 0_ft,
            .y = 0_ft,
            .theta = 0_deg 
    };

    motors_init();

    drive->/*getOdometry()->*/setState(zero_state); 

    //while (true) {
        printf("after 0 init: %lf, %lf\n",
            drive->getState().y.convert(okapi::foot), 
            drive->getState().x.convert(okapi::foot)); 
        pros::delay(280);
    //}

    motors_init();

	updateAuton();

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	pros::delay(240);	
    //drive_dis(2, 1);
/*
    auto cur_state = drive->getState();
    print_state("cur_state", cur_state);

    profile_controller->generatePath(
        {{cur_state.x, cur_state.y, cur_state.theta}, 
        {2_ft, 1_ft, 30_deg}}, "Path");          //x y flipped

    profile_controller->setTarget("Path");
    profile_controller->waitUntilSettled();

    print_cur_state();
*/
	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	// pros::Motor left_mtr(1);
	// pros::Motor right_mtr(2);

	// while (true) {
	// 	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
	// 	int left = master.get_analog(ANALOG_LEFT_Y);
	// 	int right = master.get_analog(ANALOG_RIGHT_Y);

	// 	left_mtr = left;
	// 	right_mtr = right;

	// 	pros::delay(20);

    okapi::Rate rate;       //wait does this need to be recontructed everytime it loops

	while (true) {
      //band.set_value(true);    

        updateDrive();
//      updateIntake();
//      updateCata();
//      updateSkills();
//      updateExpansion();

        rate.delay(100_Hz);         
	}
}
