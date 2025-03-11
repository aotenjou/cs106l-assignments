/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "A A"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs(filename);
  std::string stu;
  std::set<std::string> res;
  while(std::getline(ifs,stu)){
    res.emplace(stu);
  }
  return res;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> res;
  std::string initials;
    initials += name[0]; // First initial
    size_t spacePos = name.find(' ');
    if (spacePos != std::string::npos && spacePos + 1 < name.size()) {
        initials += name[spacePos + 1]; // Second initial
    }

    // Find names with the same initials
    for (const auto& student : students) {
        if (student.empty()) continue;

        std::string studentInitials;
        studentInitials += student[0]; // First initial
        size_t studentSpacePos = student.find(' ');
        if (studentSpacePos != std::string::npos && studentSpacePos + 1 < student.size()) {
            studentInitials += student[studentSpacePos + 1]; // Second initial
        }

        if (studentInitials == initials) {
            res.push(&student); // Push a pointer to the matching name
        }
    }
  return res;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  return "NO MATCHES FOUND.";
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
