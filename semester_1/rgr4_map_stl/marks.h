#include <cstddef>
#include <ostream>
#include <string>
#include <vector>
#include <map>

struct Mark {
    std::string subject_; 
    size_t mark_;
    
    Mark(const std::string& subject, size_t mark);

    void print(std::ostream& out) const;
};

struct StudentData {
    std::string name_; 
    size_t number_; 
    std::vector<Mark> marks_; 

    StudentData(const std::string& name, size_t number, const std::vector<Mark>& marks);
    void print(std::ostream& out) const;
};

void check_file(const std::string& file_name);

std::string parse_file(const std::string& file_name);

std::vector<std::string> parse_words_from_string(const std::string& str);

std::vector<StudentData> strings_to_students(const std::vector<std::string>& input_strings);

void sort_by_id(std::map<size_t, StudentData>& students_map);

double average_mark_by_student(const std::map<size_t, StudentData>& students_map);

void student_output_by_average(const std::map<size_t, StudentData>& students_map, std::ostream& out);

void student_output_from_interval_of_average(const std::map<size_t, StudentData>& students_map, std::ostream& out);

void student_output_by_subject(const std::map<size_t, StudentData>& students_map, std::ostream& out);

std::map<size_t, std::string> count_students_by_subjects(const std::map<size_t, StudentData>& students_map);


