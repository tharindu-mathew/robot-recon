#pragma once

#include "renderentity.h"
#include "fsl_common.h"
#include <random>
#include <stdexcept>
//#include "octree.h"
#include "swarmtree.h"
#include <memory>

struct GridOverlay : public VisObject {
	std::shared_ptr<SwarmOccupancyTree> occupany_grid_;
	unsigned int grid_resolution_per_side_;
	float grid_length_;
	QGLShaderProgram* shader_;
	std::map<int, cv::Vec4f> robot_color_map_;
	GridOverlay(UniformLocations& locations, std::shared_ptr<SwarmOccupancyTree> octree, unsigned int grid_resolution, 
		float grid_length, std::map<int, cv::Vec4f> robot_color_map, QGLShaderProgram* shader);

	void update_grid_position(const glm::ivec3& position);
	void create_mesh(bool initialize);
	void update(glm::mat4 global_model) override;
};

class Robot : public VisObject {

private:

	enum RobotState {
		MOVING = 0,
		STOPPING = 1,
		STOPPED = 2
	};

	enum SwarmingState {
		EXPLORING = 0,
		AT_EDGE = 1,
		GOING_INWARD
	};

	void change_state(RobotState state);

	void change_state(SwarmingState state);
	SwarmingState current_swarming_state_;
	RobotState current_robot_state_;

	bool all_goals_explored_;

	float accumulator_;
	unsigned int id_;
	glm::vec3 velocity_;
	glm::vec3 position_;
	long long timeout_;
	long long last_timeout_;
	long long last_updated_time_;
	std::mt19937 rng_;
	std::uniform_real_distribution<float> velocity_generator_;
	std::uniform_int_distribution<int> position_generator_;

	// goal position
	glm::vec3 goal_position_;

	float explore_constant_;
	float separation_constant_;
	float work_constant_;

	glm::vec3 explore_force_;
	glm::vec3 separation_force_;
	glm::vec3 work_force_;
	glm::vec3 out_of_bounds_force_;

	// seperation force requirements
	//glm::vec3 center_of_mass_;
	std::vector<std::shared_ptr<Robot>> robots_;
	float minimum_separation_distance_;
	float separation_distance_threshold_;

	// exploration force requirements
	// location in grid for frontier calculation
	float mass_;
	float max_velocity_;
	bool travelling_in_bound_;
	glm::vec3 resultant_direction_;
	float distance_to_goal_threshold_;
	glm::vec3 stopping_force_;
	glm::vec3 previous_position_;
	float robot_radius_;
	GridOverlay* overlay_;
	//int grid_cube_length_;
	//int grid_resolution_per_side_;
	//std::vector<glm::ivec3> get_adjacent_cells(const glm::ivec3& position) const;
	//bool frontier_bread_first_search(const glm::ivec3& current_cell, glm::ivec3& result_cell) const;
	//glm::ivec3 map_to_grid(const glm::vec3& position) const;
	//glm::vec3 map_to_position(const glm::ivec3& grid_position) const;
	//bool is_out_of_bounds(const glm::ivec3& position) const ;
	//bool explored_by(const glm::ivec3& position) const ;

	// kinematics
	glm::vec3 calculate_force(glm::vec3 move_to_position);
	glm::vec3 calculate_force(glm::vec3 move_to_position, float constant) const;


	std::shared_ptr<SwarmOccupancyTree> occupancy_grid_;
	std::shared_ptr<SwarmCollisionTree> collision_grid_;
	QGLShaderProgram* shader_;
	bool show_forces_;

public:
	static int MAX_DEPTH;
	void set_explore_constant(float constant);
	void set_separation_constant(float constant);
	void set_work_constant(float constant);
	void set_grid_overlay(GridOverlay* overlay);

	void calculate_explore_force();
	void calculate_separation_force(const std::vector<int>& other_robots, const std::vector<glm::vec3>& interior_cells);
	void calculate_work_force();
	void visualize_force(const int& mesh_id, const glm::vec3& force, const cv::Vec4f& color, bool initialize);

	glm::vec3 calculate_resultant_direction(const std::vector<int>& other_robots, const std::vector<glm::vec3>& interior_cells);
	Robot(UniformLocations& locations, unsigned id,
		std::shared_ptr<SwarmOccupancyTree> octree,
		std::shared_ptr<SwarmCollisionTree> collision_tree, 
		double explore_constant, double seperation_constant, 
		double work_constant, double seperation_distance, glm::vec3 position, QGLShaderProgram* shader);
	//Robot(UniformLocations& locations, unsigned int id, std::shared_ptr<SwarmOctTree> octree);

	void set_show_forces(bool show);
	void update_robots(const std::vector<std::shared_ptr<Robot>>& robots);
	//void handle_input();
	virtual void update(glm::mat4 global_model);

	Robot& operator=(const Robot& other);

	std::vector<glm::vec3> get_interior_cell_positions(const std::vector<glm::ivec3>& grid_positions) const;
	std::vector<int> get_other_robots(const std::vector<glm::ivec3>& grid_positions) const;
	void get_adjacent_cells(const glm::vec3& position, std::vector<glm::ivec3>& cells) const;
	bool is_colliding(const glm::vec3& other_object_position, float radius) const;
	bool is_colliding_with_interior(const std::vector<glm::vec3>& interior_positions) const;
	bool is_colliding_with_robots(const std::vector<int>& robot_ids) const;


	// calculate forces, 3 types of forces for now
	// calculate acceleration and integrate for velocity and position

};
