# LidarDetection
<p>Ros programs main focus on basic ros function</p>
<p>This program is design to detect object using lidar, then use the motor to open/close light</p>

<h3>Function</h3>
<p>There two ros launch, one is for a master, another is for client.</p>
<p>**test_launch** , this launch file, start a **rpllidar** launch files, then start **sublaser** node which will subscribe to the **laser_msg** and only check the 250-290 degree. <br>And determined if there anything in font of it (0.2 meter,if so then publish /motor_toggle topic.</p>
<p>Then **rosserial** so that arduino can sub/pub ros topic, this allow my arduino UNO to be able to subscribe to /motor_toggle, if it receive any message turn the motor on, and publish /status.</p>
<p>Lastly **audiocontroll.launch** is ment for a client, it will subscribe to  topic publish by arduino, and if updated play a audio, this launch file also include a kill button, if the audio get annoying</p>
<p>https://youtu.be/-NfQFspLYKQ</p>

# Setup
<p>Set one pc as a master and one as a client</p>
<br>
<p>for client</p>

```
export $ROS_MASTER_URI=http://<ros_master_ip>:11311
```

<p>make sure to git clone this repo so that you can run lidar</p>
<p>https://github.com/robopeak/rplidar_ros?tab=readme-ov-file</p>
<p>clone this too for rosserial</p>
<p>https://github.com/ros-drivers/rosserial</p>
<p>Make sure to have these useful lib</p>
<ul>
  <li>ros</li>
  <li>arduino-cli</li>
</ul>

and dont forget to 
```
catkin build
#or
catkin_make
#which ever you prefer
```

# Usage
Run the test_launch.launch then audiocontroll.launch

### Purpose
Main purpose for this small project is to learn ros.
<ul>
	<li>Ros-Ros communication</li>
    <li>Ros-Arduino communication</li>
    <li>laser_msg manipulation</li>
</ul>

# Contributing
feel free to pull. Im new tho, pls dont put me on blast.

