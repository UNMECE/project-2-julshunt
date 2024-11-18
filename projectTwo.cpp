// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem-Solving
// Project 2
// FileName: "projectTwo"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class student {
protected:
    string firstName;
    string lastName;
    float gpa;
    int gradYear;
    string gradSemester;
    int yearEnrolled;
    string semesterEnrolled;
    bool isUndergrad; // yes or no 

public:
    // Constructor
    student()
        : firstName("Unknown"), lastName("Unknown"), gpa(0.0), gradYear(0), 
          gradSemester("Unknown"), yearEnrolled(0), semesterEnrolled("Unknown"), isUndergrad(true) {}

    // Destructor (for memory allocation purposes)
    virtual ~student() {}

    // Setters
    void setName(const string& first, const string& last) {
        firstName = first;
        lastName = last;
    }

    void setGPA(float gpaValue) {
        gpa = gpaValue;
    }

    void setGradYear(int year) {
        gradYear = year;
    }

    void setYearEnrolled(int year) {
        yearEnrolled = year;
    }

    void setSemesterEnrolled(const string& semester) {
        semesterEnrolled = semester;
    }

    void setUndergradStatus(bool isUndergradStatus) {
        isUndergrad = isUndergradStatus;
    }

    // Displaying results 
    virtual void displayStudentInfo() const {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Grade Point Average: " << gpa << endl;
        cout << "Expected Graduation Year: " << gradYear << " " << gradSemester << endl;
        cout << "Year Enrolled: " << yearEnrolled << ", " << semesterEnrolled << endl;
        cout << "Undergrad Status: " << (isUndergrad ? "Yes" : "No") << endl;
    }

    string getName() const {
        return firstName + " " + lastName;
    }

    float getGPA() const {
        return gpa;
    }

    int getGradYear() const {
        return gradYear;
    }

    string getGradSemester() const {
        return gradSemester;
    }

    int getYearEnrolled() const {
        return yearEnrolled;
    }

    string getSemesterEnrolled() const {
        return semesterEnrolled;
    }

    bool getUndergradStatus() const {
        return isUndergrad;
    }
};

// Derived class for art student 
class artStudent : public student {
private:
    string artConcentrate;

public:
    artStudent()
        : student(), artConcentrate("Unknown") {}

    void setArtConcentrate(const string& concentrate) {
        artConcentrate = concentrate;
    }

    // Displaying Art Emphasis 
    void displayStudentInfo() const {
        student::displayStudentInfo();
        cout << "Art Concentration: " << artConcentrate << endl;
    }

    string getArtConcentrate() const {
        return artConcentrate;
    }
};

// Derived class for physics student 
class physicsStudent : public student {
private:
    string physicsConcentrate;

public:
    physicsStudent()
        : student(), physicsConcentrate("Unknown") {}

    void setConcentration(const string& conc) {
        physicsConcentrate = conc;
    }

    // Displaying Results 
    void displayStudentInfo() const {
        student::displayStudentInfo();
        cout << "Physics Concentration: " << physicsConcentrate << endl;
    }

    string getConcentration() const {
        return physicsConcentrate;
    }
};

int main() {
    vector<artStudent*> artStudents;
    vector<physicsStudent*> physicsStudents;

    // Create 5 ArtStudent objects and set values
    string artStudentNames[5] = { "Terrance Crews", "James Drummond", "Elizabeth Ward", "Eric Brown", "Emily-Lynn Davis" };
    for (int i = 0; i < 5; ++i) {
        artStudents.push_back(new artStudent());
        string firstName = artStudentNames[i].substr(0, artStudentNames[i].find(' '));
        string lastName = artStudentNames[i].substr(artStudentNames[i].find(' ') + 1);
        artStudents[i]->setName(firstName, lastName);
        artStudents[i]->setGPA(3.1f + i * 0.1f);
        artStudents[i]->setGradYear(2026);
        artStudents[i]->setSemesterEnrolled("Spring");
        artStudents[i]->setYearEnrolled(2022);
        artStudents[i]->setSemesterEnrolled("Fall");
        artStudents[i]->setUndergradStatus(true);
        artStudents[i]->setArtConcentrate(i % 3 == 0 ? "Art Studio" : (i % 3 == 1 ? "Art History" : "Art Education"));
    }

    // Create 5 PhysicsStudent objects and set values
    string physicsStudentNames[5] = { "Adam Silbert", "Michael Judge", "Hannah White", "Shawn Scott", "David Wilson-Hernandez" };
    for (int i = 0; i < 5; ++i) {
        physicsStudents.push_back(new physicsStudent());
        string firstName = physicsStudentNames[i].substr(0, physicsStudentNames[i].find(' '));
        string lastName = physicsStudentNames[i].substr(physicsStudentNames[i].find(' ') + 1);
        physicsStudents[i]->setName(firstName, lastName);
        physicsStudents[i]->setGPA(2.9f + i * 0.1f);
        physicsStudents[i]->setGradYear(2026);
        physicsStudents[i]->setSemesterEnrolled("Spring");
        physicsStudents[i]->setYearEnrolled(2022);
        physicsStudents[i]->setSemesterEnrolled("Fall");
        physicsStudents[i]->setUndergradStatus(true);
        physicsStudents[i]->setConcentration(i % 2 == 0 ? "Biophysics" : "Earth and Planetary Sciences");
    }

    // Write student info to a file
    ofstream outfile("studentInfo.dat", ios::out);
    if (!outfile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write art students info
    for (size_t i = 0; i < artStudents.size(); ++i) {
        outfile << "Art Student:" << endl;
        outfile << artStudents[i]->getName() << endl;
        outfile << "Grade Point Average: " << artStudents[i]->getGPA() << endl;
        outfile << "Expected Graduation Year: " << artStudents[i]->getGradYear() << endl;
        outfile << "Graduation Semester: " << artStudents[i]->getGradSemester() << endl;
        outfile << "Enrollment Year: " << artStudents[i]->getYearEnrolled() << endl;
        outfile << "Enrollment Semester: " << artStudents[i]->getSemesterEnrolled() << endl;
        outfile << "Art Concentration: " << artStudents[i]->getArtConcentrate() << endl << endl;
    }

    // Write physics students info
    for (size_t i = 0; i < physicsStudents.size(); ++i) {
        outfile << "Physics Student:" << endl;
        outfile << physicsStudents[i]->getName() << endl;
        outfile << "Grade Point Average: " << physicsStudents[i]->getGPA() << endl;
        outfile << "Expected Graduation Year: " << physicsStudents[i]->getGradYear() << endl;
        outfile << "Graduation Semester: " << physicsStudents[i]->getGradSemester() << endl;
        outfile << "Enrollment Year: " << physicsStudents[i]->getYearEnrolled() << endl;
        outfile << "Enrollment Semester: " << physicsStudents[i]->getSemesterEnrolled() << endl;
        outfile << "Physics Concentration: " << physicsStudents[i]->getConcentration() << endl << endl;
    }

    // Clean up allocated memory
    for (size_t i = 0; i < artStudents.size(); ++i) {
        delete artStudents[i];
    }
    for (size_t i = 0; i < physicsStudents.size(); ++i) {
        delete physicsStudents[i];
    }

    outfile.close();
    return 0;
}
