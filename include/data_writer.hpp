#include <fstream>
#include <string>
#include <vector>

#include "body.hpp"
#include "n_body_system.hpp"


/*Class to write simulation data to file
Data is written in the following csv format:

time1, body1_name, body1_mass, body1_position_x, body1_position_y, body1_position_z, body1_velocity_x, body1_velocity_y, body1_velocity_z

time1, body2_name, body2_mass, body2_position_x, body2_position_y, body2_position_z, body2_velocity_x, body2_velocity_y, body2_velocity_z

time2, body1_name, body1_mass, body1_position_x, body1_position_y, body1_position_z, body1_velocity_x, body1_velocity_y, body1_velocity_z

*/
class DataWriter
{
public:
    DataWriter(const std::string& file);
    void writeTimeStep(double time, const NBodySystem& n_body_system);

private:
    std::ofstream fileStream;
    void writeBody(const Body& body, std::stringstream& current_line);
};