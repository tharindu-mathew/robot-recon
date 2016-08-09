#include "swarmutils.h"
#include <tiny_obj_loader.h>
#include "renderentity.h"
#include <qsettings.h>
#include "swarmtree.h"
#include <random>
#include "experimentalrobot.h"

#define PI 3.14159265

const char* SwarmUtils::OPT_SWARM_CONFIGS_LIST = "OPT_SWARM_CONFIGS_LIST";
const char* SwarmUtils::OPT_NO_OF_THREADS = "OPT_NO_OF_THREADS";
const char* SwarmUtils::OPT_NO_OF_ITERATIONS = "OPT_NO_OF_ITERATIONS";
const char* SwarmUtils::OPT_CULLING_NTH_ITERATION = "OPT_CULLING_NTH_ITERATION";

const char* SwarmUtils::ROBOTS_NO_LABEL = "robots_no";
const char* SwarmUtils::EXPLORATION_CONSTANT_LABEL = "exploration_constant";
const char* SwarmUtils::SEPARATION_CONSTANT_LABEL = "separation_constant";
const char* SwarmUtils::ALIGNMENT_CONSTANT_LABEL = "alignment_constant";
const char* SwarmUtils::CLUSTER_CONSTANT_LABEL = "cluster_constant";
const char* SwarmUtils::PERIMETER_CONSTANT_LABEL = "perimeter_constant";
const char* SwarmUtils::GOTO_WORK_CONSTANT_LABEL = "goto_work_constant";
//const char* SwarmUtils::SEPARATION_DISTANCE_LABEL = "separation_distance";
const char* SwarmUtils::SHOW_FORCES_LABEL = "show_forces";

const char* SwarmUtils::COLLIDE_WITH_OTHER_ROBOTS_LABEL = "collide_with_other_robots";

const char* SwarmUtils::MAGICK_LABEL = "magick";
const char* SwarmUtils::FORMATION_LABEL = "formation";
const char* SwarmUtils::SENSOR_RANGE_LABEL = "sensor_range";
const char* SwarmUtils::DISCOVERY_RANGE_LABEL = "discovery_range";

const char* SwarmUtils::EXPLORE_RANGE_MIN_LABEL = "explore_range_min";
const char* SwarmUtils::SEPARATION_RANGE_MIN_LABEL = "separation_range_min";
const char* SwarmUtils::ALIGNMENT_RANGE_MIN_LABEL = "alignment_range_min";
const char* SwarmUtils::CLUSTER_RANGE_MIN_LABEL = "cluster_range_min";
const char* SwarmUtils::PERIMETER_RANGE_MIN_LABEL = "perimeter_range_min";
const char* SwarmUtils::OBSTACLE_AVOIDANCE_NEAR_RANGE_MIN_LABEL = "obstacle_avoidance_near_range_min";
const char* SwarmUtils::OBSTACLE_AVOIDANCE_NEAR_RANGE_MAX_LABEL = "obstacle_avoidance_near_range_max";

const char* SwarmUtils::EXPLORE_RANGE_MAX_LABEL = "explore_range_max";
const char* SwarmUtils::SEPARATION_RANGE_MAX_LABEL = "separation_range_max";
const char* SwarmUtils::ALIGNMENT_RANGE_MAX_LABEL = "alignment_range_max";
const char* SwarmUtils::CLUSTER_RANGE_MAX_LABEL = "cluster_range_max";
const char* SwarmUtils::PERIMETER_RANGE_MAX_LABEL = "perimeter_range_max";
const char* SwarmUtils::OBSTACLE_AVOIDANCE_FAR_RANGE_MIN_LABEL = "obstacle_avoidance_far_range_min";
const char* SwarmUtils::OBSTACLE_AVOIDANCE_FAR_RANGE_MAX_LABEL = "obstacle_avoidance_far_range_max";

const char* SwarmUtils::NEIGHBORHOOD_COUNT_LABEL = "neighborhood_count";
const char* SwarmUtils::GRID_RESOLUTION_LABEL = "grid_resolution";
const char* SwarmUtils::GRID_LENGTH_LABEL = "grid_length";
const char* SwarmUtils::BUILDING_INTERIOR_SCALE_LABEL = "interior_scale";
const char* SwarmUtils::BUILDING_OFFSET_X_LABEL = "interior_offset_x";
const char* SwarmUtils::BUILDING_OFFSET_Y_LABEL = "interior_offset_y";
const char* SwarmUtils::BUILDING_OFFSET_Z_LABEL = "interior_offset_z";
const char* SwarmUtils::SHOW_BUILDING_LABEL = "show_interior";
const char* SwarmUtils::INTERIOR_MODEL_FILENAME = "interior_model_filename";


const char* SwarmUtils::SQUARE_RADIUS = "square_radius";
const char* SwarmUtils::BOUNCE_FUNCTION_POWER = "bounce_function_power";
const char* SwarmUtils::BOUNCE_FUNCTION_MULTIPLIER = "bounce_function_multiplier";

const char* SwarmUtils::MAX_TIME_TAKEN = "max_time_taken";
const char* SwarmUtils::NO_OF_CLUSTERS = "no_of_clusters_";
const char* SwarmUtils::DEATH_PERCENTAGE = "death_percentage_";
const char* SwarmUtils::DEATH_TIME_TAKEN = "death_time_taken";


const std::string SwarmUtils::DEFAULT_INTERIOR_MODEL_FILENAME = "interior/l-shape-floor-plan.obj";

const int SwarmUtils::DEFAULT_NO_OF_ROBOTS = 3;

#define NO_OF_LIGHTS 2
#define NO_OF_ROBOTS 10
#define PI 3.14159265

const std::string SwarmUtils::OCCUPANCY_GRID_NAME = "occupancy_grid";
const std::string SwarmUtils::OCCUPANCY_GRID_OVERLAY_NAME = "occupancy_grid_overlay";
const int SwarmUtils::OCCUPANCY_GRID_HEIGHT = 2;

OptimizationParams SwarmUtils::load_optimization_params(const QString& filename) {
	QSettings settings(filename, QSettings::IniFormat);
	
	OptimizationParams optimization_params;

	optimization_params.swarm_configs = settings.value(OPT_SWARM_CONFIGS_LIST, "").toStringList();
	optimization_params.no_of_iterations = settings.value(OPT_NO_OF_ITERATIONS, "10").toInt();
	optimization_params.no_of_threads = settings.value(OPT_NO_OF_THREADS, "10").toInt();
	optimization_params.culling_nth_iteration = settings.value(OPT_CULLING_NTH_ITERATION, "5").toInt();

	return optimization_params;
}

void SwarmUtils::save_optimization_params(const OptimizationParams& params, const QString& filename) {
	QSettings settings(filename, QSettings::IniFormat);

	settings.setValue(OPT_SWARM_CONFIGS_LIST, params.swarm_configs);
	settings.setValue(OPT_NO_OF_THREADS, params.no_of_threads);
	settings.setValue(OPT_NO_OF_ITERATIONS, params.no_of_iterations);
	settings.setValue(OPT_CULLING_NTH_ITERATION, params.culling_nth_iteration);
}

SwarmParams SwarmUtils::load_swarm_params(const QString& filename) {
	QSettings settings(filename, QSettings::IniFormat);
	
	SwarmParams swarm_params;
	swarm_params.no_of_robots_ = (settings.value(ROBOTS_NO_LABEL, "10").toInt());
	swarm_params.exploration_constant_ = (settings.value(EXPLORATION_CONSTANT_LABEL, "1").toDouble());
	swarm_params.separation_constant_ = (settings.value(SEPARATION_CONSTANT_LABEL, "1").toDouble());
	swarm_params.alignment_constant_ = (settings.value(ALIGNMENT_CONSTANT_LABEL, "1").toDouble());
	swarm_params.cluster_constant_ = (settings.value(CLUSTER_CONSTANT_LABEL, "1").toDouble());
	swarm_params.perimeter_constant_ = (settings.value(PERIMETER_CONSTANT_LABEL, "1").toDouble());
	swarm_params.goto_work_constant_ = (settings.value(GOTO_WORK_CONSTANT_LABEL, "1").toDouble());

	swarm_params.formation = (settings.value(FORMATION_LABEL, "0").toInt());

	swarm_params.grid_resolution_ = (settings.value(GRID_RESOLUTION_LABEL, "4096").toInt());
	swarm_params.grid_length_ = (settings.value(GRID_LENGTH_LABEL, "20").toInt());

	swarm_params.sensor_range_ = (settings.value(SENSOR_RANGE_LABEL, "5").toDouble());

	swarm_params.discovery_range_ = (settings.value(DISCOVERY_RANGE_LABEL, "0").toInt());

	swarm_params.separation_range_min_ = (settings.value(SEPARATION_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.separation_range_max_ = (settings.value(SEPARATION_RANGE_MAX_LABEL, "1").toDouble());

	swarm_params.alignment_range_min_ = (settings.value(ALIGNMENT_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.alignment_range_max_ = (settings.value(ALIGNMENT_RANGE_MAX_LABEL, "1").toDouble());

	swarm_params.cluster_range_min_ = (settings.value(CLUSTER_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.cluster_range_max_ = (settings.value(CLUSTER_RANGE_MAX_LABEL, "1").toDouble());

	swarm_params.perimeter_range_min_ = (settings.value(PERIMETER_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.perimeter_range_max_ = (settings.value(PERIMETER_RANGE_MAX_LABEL, "1").toDouble());

	swarm_params.explore_range_min_ = (settings.value(EXPLORE_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.explore_range_max_ = (settings.value(EXPLORE_RANGE_MAX_LABEL, "1").toDouble());


	swarm_params.obstacle_avoidance_far_range_min_ = (settings.value(OBSTACLE_AVOIDANCE_FAR_RANGE_MIN_LABEL, "1").toDouble());
	swarm_params.obstacle_avoidance_far_range_max_ = (settings.value(OBSTACLE_AVOIDANCE_FAR_RANGE_MAX_LABEL, "5").toDouble());

	swarm_params.obstacle_avoidance_near_range_min_ = (settings.value(OBSTACLE_AVOIDANCE_NEAR_RANGE_MIN_LABEL, "0").toDouble());
	swarm_params.obstacle_avoidance_near_range_max_ = (settings.value(OBSTACLE_AVOIDANCE_NEAR_RANGE_MAX_LABEL, "1").toDouble());


	//separation_distance_->setValue(settings.value(SEPARATION_DISTANCE_LABEL, "100").toDouble());


	swarm_params.model_filename_ = (settings.value(INTERIOR_MODEL_FILENAME, "interior/house interior.obj").toString());


	swarm_params.scale_spinbox_ = (settings.value(BUILDING_INTERIOR_SCALE_LABEL, "2").toDouble());
	swarm_params.x_spin_box_ = (settings.value(BUILDING_OFFSET_X_LABEL, "0").toInt());
	swarm_params.y_spin_box_ = (settings.value(BUILDING_OFFSET_Y_LABEL, "0").toInt());
	swarm_params.z_spin_box_ = (settings.value(BUILDING_OFFSET_Z_LABEL, "0").toInt());

	swarm_params.show_interior_ = settings.value(SHOW_BUILDING_LABEL, "1").toBool();

	swarm_params.show_forces_ = settings.value(SHOW_FORCES_LABEL, "1").toBool();

	swarm_params.collide_with_other_robots_ = settings.value(COLLIDE_WITH_OTHER_ROBOTS_LABEL, "1").toBool();

	swarm_params.neighborhood_count_ = (settings.value(NEIGHBORHOOD_COUNT_LABEL, "5").toInt());

	swarm_params.magic_k_spin_box_ = (settings.value(MAGICK_LABEL, "0.1").toDouble());
	swarm_params.square_radius_ = (settings.value(SQUARE_RADIUS, "4.0").toDouble());
	swarm_params.bounce_function_power_ = (settings.value(BOUNCE_FUNCTION_POWER, "3.0").toDouble());
	swarm_params.bounce_function_multiplier_ = (settings.value(BOUNCE_FUNCTION_MULTIPLIER, "1.0").toDouble());

	swarm_params.max_time_taken_ = (settings.value(MAX_TIME_TAKEN, "20000").toInt());
	swarm_params.no_of_clusters_ = (settings.value(NO_OF_CLUSTERS, "1").toInt());
	swarm_params.death_time_taken_ = (settings.value(DEATH_TIME_TAKEN, "2000").toInt());
	swarm_params.death_percentage_ = (settings.value(DEATH_PERCENTAGE, "0.0").toDouble());
	return swarm_params;
}


void SwarmUtils::save_swarm_params(const SwarmParams& params, const QString& filename) {
	QSettings settings(filename, QSettings::IniFormat);


	settings.setValue(ROBOTS_NO_LABEL, params.no_of_robots_);
	settings.setValue(EXPLORATION_CONSTANT_LABEL, params.exploration_constant_);
	settings.setValue(SEPARATION_CONSTANT_LABEL, params.separation_constant_);
	settings.setValue(ALIGNMENT_CONSTANT_LABEL, params.alignment_constant_);
	settings.setValue(CLUSTER_CONSTANT_LABEL, params.cluster_constant_);
	settings.setValue(PERIMETER_CONSTANT_LABEL, params.perimeter_constant_);
	settings.setValue(GOTO_WORK_CONSTANT_LABEL, params.goto_work_constant_);

	settings.setValue(SEPARATION_RANGE_MIN_LABEL, params.separation_range_min_);
	settings.setValue(SEPARATION_RANGE_MAX_LABEL, params.separation_range_max_);

	settings.setValue(ALIGNMENT_RANGE_MIN_LABEL, params.alignment_range_min_);
	settings.setValue(ALIGNMENT_RANGE_MAX_LABEL, params.alignment_range_max_);

	settings.setValue(CLUSTER_RANGE_MIN_LABEL, params.cluster_range_min_);
	settings.setValue(CLUSTER_RANGE_MAX_LABEL, params.cluster_range_max_);

	settings.setValue(PERIMETER_RANGE_MIN_LABEL, params.perimeter_range_min_);
	settings.setValue(PERIMETER_RANGE_MAX_LABEL, params.perimeter_range_max_);

	settings.setValue(EXPLORE_RANGE_MIN_LABEL, params.explore_range_min_);
	settings.setValue(EXPLORE_RANGE_MAX_LABEL, params.explore_range_max_);

	settings.setValue(OBSTACLE_AVOIDANCE_NEAR_RANGE_MIN_LABEL, params.obstacle_avoidance_near_range_min_);
	settings.setValue(OBSTACLE_AVOIDANCE_NEAR_RANGE_MAX_LABEL, params.obstacle_avoidance_near_range_max_);

	settings.setValue(OBSTACLE_AVOIDANCE_FAR_RANGE_MIN_LABEL, params.obstacle_avoidance_far_range_min_);
	settings.setValue(OBSTACLE_AVOIDANCE_FAR_RANGE_MAX_LABEL, params.obstacle_avoidance_far_range_max_);

	settings.setValue(SENSOR_RANGE_LABEL, params.sensor_range_);

	settings.setValue(DISCOVERY_RANGE_LABEL, params.discovery_range_);

	settings.setValue(FORMATION_LABEL, params.formation);
	
	settings.setValue(MAGICK_LABEL, params.magic_k_spin_box_);

	settings.setValue(NEIGHBORHOOD_COUNT_LABEL, params.neighborhood_count_);
	
	//settings.setValue(SEPARATION_DISTANCE_LABEL, separation_distance_->value());

	settings.setValue(GRID_RESOLUTION_LABEL, params.grid_resolution_);
	settings.setValue(GRID_LENGTH_LABEL, params.grid_length_);

	settings.setValue(BUILDING_INTERIOR_SCALE_LABEL, params.scale_spinbox_);
	settings.setValue(BUILDING_OFFSET_X_LABEL, params.x_spin_box_);
	settings.setValue(BUILDING_OFFSET_Y_LABEL, params.y_spin_box_);
	settings.setValue(BUILDING_OFFSET_Z_LABEL, params.z_spin_box_);
	settings.setValue(SHOW_BUILDING_LABEL, params.show_interior_);
	settings.setValue(INTERIOR_MODEL_FILENAME, params.model_filename_);

	settings.setValue(SHOW_FORCES_LABEL, params.show_forces_);

	settings.setValue(COLLIDE_WITH_OTHER_ROBOTS_LABEL, params.collide_with_other_robots_);

	settings.setValue(SQUARE_RADIUS, params.square_radius_);
	settings.setValue(BOUNCE_FUNCTION_POWER, params.bounce_function_power_);
	settings.setValue(BOUNCE_FUNCTION_MULTIPLIER, params.bounce_function_multiplier_);

	
	settings.setValue(MAX_TIME_TAKEN, params.max_time_taken_);
	settings.setValue(DEATH_PERCENTAGE, params.death_percentage_);
	settings.setValue(NO_OF_CLUSTERS, params.no_of_clusters_);
	settings.setValue(DEATH_TIME_TAKEN, params.death_time_taken_);
}

void SwarmUtils::print_vector(const std::string& name, const glm::vec3& vector) {
//#ifdef DEBUG
	std::cout << name << " : " << vector.x << ", " << vector.y << ", " << vector.z << std::endl;
//#endif
}

cv::Mat SwarmUtils::convert_mat(glm::mat3& input_mat) {

	cv::Mat mat(3, 3, CV_32F, glm::value_ptr(input_mat));
	cv::Mat transposed_mat = mat.t();
	return transposed_mat;
}

void SwarmUtils::load_obj(std::string filename,  std::vector<cv::Vec3f>& vertices,
	std::vector<cv::Vec3f>& normals, std::vector<cv::Vec2f>& uvs, std::vector<unsigned int>& indices,
	std::vector<int>& count, std::vector<int>& offset, std::vector<int>& base_index) {

	std::vector<unsigned int> glm_indices;
	std::vector<glm::vec3> glm_vertices;
	std::vector<glm::vec2> glm_uvs;
	std::vector<glm::vec3> glm_normals;
	//loadAssImp(filename.c_str(), glm_indices, glm_vertices, glm_uvs, glm_normals);

	std::vector<tinyobj::shape_t> shapes;
	std::vector < tinyobj::material_t> materials;
	std::string error;
	tinyobj::LoadObj(shapes, materials, error, filename.c_str());

	//std::vector<int> count;
	//std::vector<int> offset;

	
	const int no_of_vertices_per_polygon = 3;
	int total_offset = 0;
	int total_indices = 0;
	for (auto& shape : shapes) {
		auto& mesh = shape.mesh;

		assert(mesh.indices.size() % no_of_vertices_per_polygon == 0);
		assert(mesh.positions.size() % no_of_vertices_per_polygon == 0);

		for (size_t i = 0; i < (mesh.positions.size() / no_of_vertices_per_polygon); ++i) {
			glm::vec3 position(mesh.positions[(no_of_vertices_per_polygon * i) + 0], 
				mesh.positions[(no_of_vertices_per_polygon * i) + 1], 
				mesh.positions[(no_of_vertices_per_polygon * i) + 2]);
			glm::vec3 normal(mesh.normals[(no_of_vertices_per_polygon * i) + 0], 
				mesh.normals[(no_of_vertices_per_polygon * i) + 1], 
				mesh.normals[(no_of_vertices_per_polygon * i) + 2]);
			if (mesh.texcoords.size() > 0 && (mesh.texcoords.size() > 2 * i)) {
				glm::vec2 texcoord(mesh.texcoords[(2 * i) + 0],
					mesh.texcoords[(2 * i) + 1]);
				glm_uvs.push_back(texcoord);
			}
			glm_vertices.push_back(position);
			glm_normals.push_back(normal);
		}

		int no_of_vertices = mesh.positions.size() / 3;

		int indices_count = mesh.indices.size();
		for (size_t i = 0; i < indices_count; ++i) {
			glm_indices.push_back(mesh.indices[i]);
		}
		count.push_back(indices_count);
		offset.push_back(total_offset);
		base_index.push_back(total_indices);

		total_offset += (no_of_vertices);
		total_indices += indices_count;
	}
	
	for (auto& out_vertice : glm_vertices) {
		vertices.push_back(cv::Vec3f(static_cast<float>(out_vertice[0]), static_cast<float>(out_vertice[1])
			, static_cast<float>(out_vertice[2])));
	}

	for (auto& out_vertice : glm_normals) {
		normals.push_back(cv::Vec3f(static_cast<float>(out_vertice[0]), static_cast<float>(out_vertice[1])
			, static_cast<float>(out_vertice[2])));
	}

	for (auto& out_vertice : glm_uvs) {
		uvs.push_back(cv::Vec2f(static_cast<float>(out_vertice[0]), static_cast<float>(out_vertice[1])));
	}

	indices = glm_indices;
}

void SwarmUtils::load_obj(std::string filename, VertexBufferData& vertex_buffer_data) {
	load_obj(filename, vertex_buffer_data.positions, vertex_buffer_data.normals, vertex_buffer_data.uvs,
		vertex_buffer_data.indices, vertex_buffer_data.count, vertex_buffer_data.offset, vertex_buffer_data.base_index);
}

std::vector<glm::vec3> SwarmUtils::create_starting_formation(Formation type, SwarmParams& swarm_params, SwarmOccupancyTree* occupancy_grid_) {
	std::vector<glm::vec3> robot_positions;

	switch (type) {
	case SQUARE: {
		double side_length = swarm_params.square_radius_ * swarm_params.grid_length_ * 2;
		double distance_between_robots = side_length * 4.0 / (double)swarm_params.no_of_robots_;

		glm::vec3 robots_mid_point(side_length / 2.f, 0.f, side_length / 2.f);
		glm::vec3 grid_mid_point(swarm_params.grid_resolution_per_side_ / 2.0 * swarm_params.grid_length_, 0.f, 
			swarm_params.grid_resolution_per_side_ / 2.0 * swarm_params.grid_length_);
		glm::vec3 offset = grid_mid_point - robots_mid_point;

		for (int i = 0; i < swarm_params.no_of_robots_; ++i) {
			double robot_position_on_line = i * distance_between_robots;
			int square_segment = std::floor(robot_position_on_line / side_length);
			double left_over_distance = std::fmod(robot_position_on_line, side_length);

			glm::vec3 square_starting_position;
			glm::vec3 added_distance;

			switch (square_segment) {
			case 0: {
				square_starting_position = glm::vec3(0.f, 0.f, 0.f);
				added_distance = glm::vec3(left_over_distance, 0.f, 0.f);
				break;
			}
			case 1: {
				square_starting_position = glm::vec3(side_length, 0.f, 0.f);
				added_distance = glm::vec3(0.f, 0.f, left_over_distance);
				break;
			}
			case 2: {
				square_starting_position = glm::vec3(side_length, 0.f, side_length);
				added_distance = glm::vec3(-left_over_distance, 0.f, 0.f);
				break;
			}
			case 3: {
				square_starting_position = glm::vec3(0.f, 0.f, side_length);
				added_distance = glm::vec3(0.f, 0.f, -left_over_distance);
				break;
			}
			default: {
				std::cout << "Something bad happened\n";
				break;
			}
			}

			glm::vec3 robot_position = square_starting_position + added_distance + offset;
			try {
				auto robot_grid_position = occupancy_grid_->map_to_grid(robot_position);
				if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
					&& !occupancy_grid_->is_interior(robot_grid_position)) {
					robot_positions.push_back(robot_position);
				}
			} catch (OutOfGridBoundsException& ex) {
				// ignore
			}
		}



		//int no_of_robots_per_side = ((no_of_robots_ - 4)/ 4.f) + 2;
		//glm::ivec3 robots_mid_point((no_of_robots_per_side / 2.f) - 1, 0, (no_of_robots_per_side / 2.f) - 1);
		//glm::ivec3 mid_point((grid_resolution_per_side_ / 2.f) - 1, 0, (grid_resolution_per_side_ / 2.f) - 1);
		//glm::ivec3 offset = mid_point - robots_mid_point;
		//
		//for (int x = 0; x < no_of_robots_per_side; ++x) {
		//	for (int z = 0; z < no_of_robots_per_side; z++) {
		//		if ((z == 0 || z == (no_of_robots_per_side - 1)) || (x == 0 || x == (no_of_robots_per_side - 1))) {

		//			//SwarmUtils::print_vector("init pos : ", glm::ivec3(x, 0, z));

		//			glm::ivec3 robot_grid_position = glm::ivec3(x, 0, z) + offset;

		//			glm::vec3 push_back_offset;
		//			glm::vec3 real_mid_point (grid_resolution_per_side_ * grid_length_ / 2.f, 0, grid_resolution_per_side_ * grid_length_ / 2.f);
		//			glm::vec3 vector_from_mid_point = glm::vec3(occupancy_grid_->map_to_position(robot_grid_position) - real_mid_point);
		//			auto length_from_mid_point = glm::length(vector_from_mid_point);
		//			
		//			if (length_from_mid_point > 1e-6) {
		//				float square_length = square_radius_ *  grid_length_;
		//				float cos_theta = 1.f;

		//				if ((x == 0 || x == (no_of_robots_per_side - 1)) && (z == 0 || z == (no_of_robots_per_side - 1))) {
		//					cos_theta = std::cos(glm::radians(45.f));
		//					//std::cout << "1\n";
		//				} else if (z == 0 || z == (no_of_robots_per_side - 1)) {
		//					cos_theta = glm::dot(glm::vec3(0.f, 0.f, 1.f), glm::normalize(vector_from_mid_point));
		//				} else if (x == 0 || x == (no_of_robots_per_side - 1)) {
		//					cos_theta = glm::dot(glm::vec3(1.f, 0.f, 0.f), glm::normalize(vector_from_mid_point));
		//				}

		//				float push_back_length = square_length / std::abs(cos_theta);
		//				//std::cout  << "\n" << x << ", " << z << " : " 
		//				//	<< std::abs(cos_theta) << " " << length_from_mid_point << " " << push_back_length << std::endl;
		//				//SwarmUtils::print_vector("robot grid pos", robot_grid_position);
		//				//SwarmUtils::print_vector("real mid point", real_mid_point);
		//				//SwarmUtils::print_vector("vector from mid point", vector_from_mid_point);
		//				

		//				//push_back_length = 0.f;
		//				push_back_offset = push_back_length * (glm::normalize(vector_from_mid_point));
		//			}

		//			if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
		//				&& !occupancy_grid_->is_interior(robot_grid_position)) {
		//				auto robot_position = occupancy_grid_->map_to_position(robot_grid_position) + push_back_offset;
		//				robot_positions.push_back(robot_position);
		//			}
		//		}
		//	}
		//}

		//int z = no_of_robots_per_side;
		//int x = 0;

		//std::cout << "No of robots : " << no_of_robots_per_side << " " << robot_positions.size() << std::endl;

		swarm_params.no_of_robots_ = robot_positions.size();
		break;
	}
	case SQUARE_CLOSE_TO_EDGE: {
		//int no_of_robots_per_side = ((no_of_robots_ - 4)/ 4.f) + 2;
		//glm::ivec3 robots_mid_point((no_of_robots_per_side / 2) - 1, 0, (no_of_robots_per_side / 2) - 1);
		//glm::ivec3 mid_point((grid_resolution_per_side_ / 2) - 1, 0, (grid_resolution_per_side_ / 2) - 1);
		//glm::ivec3 offset = mid_point - robots_mid_point;

		int distance_from_edge = 5;
		
		for (int x = 0; x < swarm_params.grid_resolution_per_side_ - 1; ++x) {
			for (int z = 0; z < swarm_params.grid_resolution_per_side_ - 1; z++) {
				if (((x - distance_from_edge == 0) || (swarm_params.grid_resolution_per_side_ - 1 - x - distance_from_edge == 0)) && 
					((z - distance_from_edge >= 0) && (swarm_params.grid_resolution_per_side_ - 1 - z - distance_from_edge >= 0)) ||
					(((z - distance_from_edge == 0) || (swarm_params.grid_resolution_per_side_ - 1 - z - distance_from_edge == 0)) && 
					((x - distance_from_edge >= 0) && (swarm_params.grid_resolution_per_side_ - 1 - x - distance_from_edge >= 0)))) {

					glm::ivec3 robot_grid_position = glm::ivec3(x, 0, z); // +offset;
					if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
						&& !occupancy_grid_->is_interior(robot_grid_position)) {
						if (robot_positions.size() < swarm_params.no_of_robots_) {
							robot_positions.push_back(occupancy_grid_->map_to_position(robot_grid_position));
						}
						//SwarmUtils::print_vector("Grid Pos : ", robot_grid_position);
					}
				}
			}
		}

		//int z = no_of_robots_per_side;
		//int x = 0;

		//std::cout << "No of robots : " << robot_positions.size() << std::endl;
		swarm_params.no_of_robots_ = robot_positions.size();
		break;
	}
	case GRID: {
		int robots_per_side = std::sqrt(swarm_params.no_of_robots_);
		glm::ivec3 robots_mid_point((robots_per_side / 2) - 1, 0, (robots_per_side / 2) - 1);
		glm::ivec3 mid_point((swarm_params.grid_resolution_per_side_ / 2) - 1, 0, (swarm_params.grid_resolution_per_side_ / 2) - 1);
		glm::ivec3 offset = mid_point - robots_mid_point;
		
		for (int x = 0; x < robots_per_side; ++x) {
			for (int z = 0; z < robots_per_side; z++) {
				//if ((z == 0 || z == (swarm_params.no_of_robots_per_side - 1)) || (x == 0 || x == swarm_params.no_of_robots_per_side - 1)) {
					glm::ivec3 robot_grid_position = glm::ivec3(x, 0, z) + offset;
					if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
						&& !occupancy_grid_->is_interior(robot_grid_position)) {
						robot_positions.push_back(occupancy_grid_->map_to_position(robot_grid_position));
					}
				//}
			}
		}

		int z = robots_per_side;
		int x = 0;

		swarm_params.no_of_robots_ = robot_positions.size();
		//while (robot_positions.size() < swarm_params.no_of_robots_) {
		//	std::cout << "Unable to fill all positions. Robots left : " << swarm_params.no_of_robots_ - robot_positions.size() << std::endl;
		//	glm::ivec3 robot_grid_position = glm::ivec3(x++, 0, z) + offset;
		//	occupancy_grid_->map_to_position(robot_grid_position);
		//	if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
		//		&& !occupancy_grid_->is_interior(robot_grid_position)) {
		//		robot_positions.push_back(occupancy_grid_->map_to_position(robot_grid_position));
		//	}
		//}
		break;

	}
	case RANDOM: {
		std::random_device rd;
		std::mt19937 rng;
		rng.seed(rd());
		std::uniform_int_distribution<int> position_generator(0, swarm_params.grid_resolution_per_side_ - 1);
		int robot_count = 0;
		int iterations = 0;
		while ((swarm_params.no_of_robots_ != robot_count) && ((swarm_params.no_of_robots_ + 100) > iterations)) {
			glm::ivec3 robot_grid_position(position_generator(rng), 0, position_generator(rng));
			if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
				&& !occupancy_grid_->is_interior(robot_grid_position)) {
				robot_positions.push_back(occupancy_grid_->map_to_position(robot_grid_position));
				robot_count++;
			}
			iterations++;
		}
		break;
	}
	case CIRCLE: {
		float perimeter_length = 2 * swarm_params.grid_length_ * swarm_params.no_of_robots_;
		float radius = perimeter_length / (2 * PI);
		glm::vec3 real_mid_point(swarm_params.grid_resolution_per_side_ * swarm_params.grid_length_ / 2.f, 0, swarm_params.grid_resolution_per_side_ * swarm_params.grid_length_ / 2.f);
		glm::vec3 center = real_mid_point;

		for (int i = 0; i < swarm_params.no_of_robots_; ++i) {
			float theta = 2 * PI * i / swarm_params.no_of_robots_;
			float x = center.x + radius * glm::cos(theta);
			float z = center.z + radius * glm::sin(theta);
			auto robot_position = glm::vec3(x, 0.f, z);
			auto robot_grid_position = occupancy_grid_->map_to_grid(robot_position);
			if (!occupancy_grid_->is_out_of_bounds(robot_grid_position)
				&& !occupancy_grid_->is_interior(robot_grid_position)) {
				robot_positions.push_back(robot_position);
			}
		}
		swarm_params.no_of_robots_ = robot_positions.size();

	}

	default: break;

	}

	return robot_positions;
}

bool SwarmUtils::intersect(const cv::Vec3f& n, float d, 
	const cv::Vec3f& a, const cv::Vec3f& b, cv::Vec3f& intersection_pt) {

	cv::Vec3f v = b - a;

	float denominator = n.dot(v);
	if (std::abs(denominator) < 1e-6) {
		return false;
	}

	float numerator = d - n.dot(a);
	float t = numerator / denominator;

	if (t >= 0 && t <= 1) {
		intersection_pt = a + t * v;
		return true;
	}
	return false;
}

void SwarmUtils::derive_floor_plan(const VertexBufferData& bufferdata, float scale, const glm::vec3& offset,
	SwarmOccupancyTree* occupancy_grid_, Swarm3DReconTree* recon_grid_) {

	std::vector<std::vector<cv::Vec3f>> triangle_list;
	cv::Vec3f vertex_offset(offset.x, offset.y, offset.z);
	glm::mat4 model_rotation;
	glm::mat3 rot_mat = glm::mat3(model_rotation);
	cv::Mat rotation_mat = convert_mat(rot_mat);

	int total_count = 0;
	for (size_t i = 0; i < bufferdata.count.size(); ++i) {
		// get triangle vertices

		int index_offset = bufferdata.base_index[i];
		int base_vertex = bufferdata.offset[i];
		std::vector<cv::Vec3f> triangle;
		for (size_t j = 0; j < bufferdata.count[i]; ++j) {
			int index = bufferdata.indices[index_offset + j];
			cv::Mat rotated_point_matrix = rotation_mat * cv::Mat(bufferdata.positions[base_vertex + index]);
			cv::Vec3f rotated_point((float*)rotated_point_matrix.datastart);
			cv::Vec3f triangle_point = scale * (rotated_point + vertex_offset);
			triangle.push_back(triangle_point);
			if ((j+1) % 3 == 0 && j > 0) {
				triangle_list.push_back(triangle);
				triangle.clear();
			}
		}
		total_count += bufferdata.count[i];
	}

	total_count /= 3;

	// get floor plane
	cv::Vec3f n(0.f, OCCUPANCY_GRID_HEIGHT, 0.f);
	float d = OCCUPANCY_GRID_HEIGHT * OCCUPANCY_GRID_HEIGHT;

	// for each triangle, check if 2 sides intersect with the plane,
	// then rasterize that line to the grid (bresenham line algorithm)
	for (auto& triangle : triangle_list) {
		assert(triangle.size() == 3);
		std::vector<glm::vec3> intersection_points;
		for (int i = 0; i < 3; ++i) {
			cv::Vec3f a = triangle[i];
			int b_index = (i == 2) ? 0 : i + 1;
			cv::Vec3f b = triangle[b_index];

			cv::Vec3f intersection_pt;
			bool does_intersect = intersect(n, d, a, b, intersection_pt);

			if (does_intersect) {
				intersection_points.push_back(glm::vec3(intersection_pt[0], intersection_pt[1],
					intersection_pt[2]));
			}

			if ((a[1] > OCCUPANCY_GRID_HEIGHT && b[1] < OCCUPANCY_GRID_HEIGHT)
				|| (a[1] < OCCUPANCY_GRID_HEIGHT && b[1] > OCCUPANCY_GRID_HEIGHT)) {
				std::string result = (does_intersect) ? "true" : "false";
				//std::cout << "Does intersect. Algorithm output : " <<  result << std::endl;
				assert(does_intersect);
			}
		}
			


		assert(intersection_points.size() == 0 || intersection_points.size() == 2);
		if (intersection_points.size() == 2) {
			occupancy_grid_->mark_interior_line(intersection_points[0],
				intersection_points[1]);
			//recon_grid_->mark_interior_line(intersection_points[0],
			//	intersection_points[1]);
		}

		glm::vec3 points[3];
		for (int i = 0; i < 3; ++i) {
			points[i] = glm::vec3(triangle[i][0], triangle[i][1], triangle[i][2]);
		}
		recon_grid_->mark_random_points_in_triangle(points[0], points[1], points[2]);
	}

	//	for (int z = 0; z < grid_resolution_per_side_; ++z) {
	//		for (int x = 0; x < grid_resolution_per_side_; ++x) {
	//			auto empty_return_value = recon_grid_->get_3d_points(glm::ivec3(x, 0, z));
	//			std::cout << "(" << x << ", " << z << ") -> " << empty_return_value->size() << "\n";
	//	}
	//}



	// remove interior of the interiors
	//occupancy_grid_->remove_inner_interiors();
}

void SwarmUtils::load_interior_model(SwarmParams& swarm_params, VertexBufferData*& vertex_buffer_data) {
	cv::Mat unit_matrix = cv::Mat::eye(4, 4, CV_64F);

	std::string model_filename = (swarm_params.model_filename_.compare("") == 0) ? DEFAULT_INTERIOR_MODEL_FILENAME
		: swarm_params.model_filename_.toStdString();

	vertex_buffer_data = new VertexBufferData();
	load_obj(model_filename,  *vertex_buffer_data);

	float scale = swarm_params.scale_spinbox_;

	if (swarm_params.model_filename_.compare("") > 0) {
		derive_floor_plan(*vertex_buffer_data, scale, glm::vec3(swarm_params.x_spin_box_, swarm_params.y_spin_box_, swarm_params.z_spin_box_));
	}

	//delete vertex_buffer_data;
}

void SwarmUtils::create_robots(SwarmParams& swarm_params, std::unordered_map<int, int>& death_map_,
	SwarmOccupancyTree* occupancy_grid_, SwarmCollisionTree* collision_grid_, Swarm3DReconTree* recon_grid_, UniformLocations& uniform_locations,
	QGLShaderProgram* shader, bool render, std::vector<Robot*>& robots) {

	std::vector<glm::vec3> robot_positions = create_starting_formation(static_cast<Formation>(swarm_params.formation), swarm_params,
		occupancy_grid_);

	assert(swarm_params.no_of_robots_ == robot_positions.size());

	populate_death_map(swarm_params, death_map_);

	int no_of_clusters = (swarm_params.no_of_clusters_ > swarm_params.no_of_robots_) ? swarm_params.no_of_robots_ : swarm_params.no_of_clusters_;
	int robots_in_a_cluster = swarm_params.no_of_robots_ / no_of_clusters;
		
	for (int i = 0; i < swarm_params.no_of_robots_; ++i) {
		std::random_device rd;
		std::mt19937 rng;
		rng.seed(rd());
		auto separation_distance = swarm_params.separation_range_max_ * swarm_params.grid_length_;
		ExperimentalRobot* robot = new ExperimentalRobot(uniform_locations, 
			i, occupancy_grid_, collision_grid_, recon_grid_, i / robots_in_a_cluster, 
			swarm_params.separation_constant_, swarm_params.alignment_constant_,swarm_params. cluster_constant_, swarm_params.explore_constant_,
			swarm_params.sensor_range_, swarm_params.discovery_range_, 
			separation_distance, robot_positions[i], swarm_params.square_radius_, swarm_params.bounce_function_power_,
			swarm_params.bounce_function_multiplier_, swarm_params.max_time_taken_,
			false, render, shader);


		robot->set_death_time(death_map_[i]);

		robots.push_back(robot);
	}
}

void SwarmUtils::populate_death_map(SwarmParams& swarm_params, std::unordered_map<int, int>& death_map_) {

	std::set<int> dying_robots;

	for (int i = 0; i < swarm_params.no_of_robots_; ++i) {
		death_map_[i] = -1;
	}

	int no_of_dead_robots = swarm_params.no_of_robots_ * swarm_params.death_percentage_;

	int dead_robots_count = 0;

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> robot_distribution(0, swarm_params.no_of_robots_ - 1);
	std::uniform_int_distribution<int> death_time_distribution(0, swarm_params.death_time_taken_- 1);

	while (no_of_dead_robots > dead_robots_count) {
		int robot_id = robot_distribution(eng);
		if (dying_robots.find(robot_id) == dying_robots.end()) {
			if (death_map_.find(robot_id) == death_map_.end()) {
				std::cout << "Unknown robot_id : " << robot_id << "\n";
			} else {
				int death_time = death_time_distribution(eng);
				death_map_[robot_id] = death_time;
				dead_robots_count++;
			}
			dying_robots.insert(robot_id);
		}
	}
	
}
