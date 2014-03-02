/*
 * Manipulation Lab
 * pick_and_place_node.cpp
 *
 *  Created on: May 21, 2013
 *      Author: ros developer 
 */

#include <pick_and_place/pick_and_place.h>

pick_and_place_config cfg;  // global var

// =============================== Main Thread ===============================
int main(int argc,char** argv)
{
  geometry_msgs::Pose box_pose;
  std::vector<geometry_msgs::Pose> pick_poses, place_poses;

  /* =========================================================================================*/
  /*	INITIALIZING ROS NODE
      Goal:
      - Observe all steps needed to properly initialize a ros node.
      - Look into the 'cfg' global var to take notice of the parameters that
        are available for the rest of the program. */
  /* =========================================================================================*/

  // ros initialization
  ros::init(argc,argv,"pick_and_place_node");
  ros::NodeHandle nh;
  //tf::TransformListener tf_listener; // queries tf to find transforms
  ros::AsyncSpinner spinner(2);
  spinner.start();

  // moveit interface initialization
  move_group_interface::MoveGroup move_group(cfg.ARM_GROUP_NAME);




  /* ========================================*/
  /* Pick & Place Tasks                      */
  /* ========================================*/

  // move to a "clear" position
  move_to_wait_position(move_group);



  return 0;
}
