#include <string>
#include <sstream>

#include "data_writer.hpp"
#include "n_body_system.hpp"
#include "body.hpp"

DataWriter::DataWriter(const std::string& file)
    : fileStream{ file }
{
}

// Write the time step with all body positions to the file
void DataWriter::writeTimeStep(
    double time,
    const NBodySystem& n_body_system)
{
    for (const Body& body : n_body_system.getBodies())
    {
        // Use a stringstream to build the line, it supports scientific notation
        std::stringstream current_line_stream;
        current_line_stream << time;
        writeBody(body, current_line_stream);
        current_line_stream << "\n";
        // Add the line to the file
        fileStream << current_line_stream.str();
    }
}

void DataWriter::writeBody(const Body& body, std::stringstream& current_line) const
{
    current_line << ", " << body.name;
    current_line << ", " << body.mass;
    for (const double& position : body.position)
    {
        current_line << ", " << position;
    }
    for (const double& velocity : body.velocity)
    {
        current_line << ", " << velocity;
    }
}