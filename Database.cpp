/**
Charlie Liu
Kolby Ramirez
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 5 - Database
*/

#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Database.h"
#include <string>


Database::Database()
{
  srand(time(NULL));

  printOptions();
  string userInput = "";
  currentSave = 0;



  loadFromFile("Test.txt");

  do {
    cout << "Please select an option: " << endl;
    getline(cin, userInput);

  } while(run(atoi(userInput.c_str())));
}

Database::~Database()
{
  cout << "Saving..." << endl;
  saveToFile("Test.txt");
}



unsigned int Database::assignID(string type)
{
  if (type == "student")
  {
    Student temp;
    unsigned int attempts = 0;
    do
    {
      temp.id = rand() % 89999 + 10000; //random number between 10000 and 99999
      if (++attempts > 10000) // If this runs more than 10000 times and no free ID has been found, program assigns ID of 0.
      {
        cout << "ID assignment timed out." << endl;
        return 0;
      }
    } while (studentTable.contains(temp));

    return temp.id;
  }

  else if(type == "faculty")
  {
    Faculty temp;
    unsigned int attempts = 0;
    do
    {
      temp.id = rand() % 9999; //random number between 1 and 9999
      if (++attempts > 10000) // If this runs more than 10000 times and no free ID has been found, program assigns ID of 0.
      {
        cout << "ID assignment timed out." << endl;
        return 0;
      }
    } while (facultyTable.contains(temp));
    cout << "ID assigned: " << temp.id << endl;
    return temp.id;
  }
  else
  {
    cout << "You are wrong" << endl;
    return 0;
  }
}

bool Database::addStudent(string name, string level, string major, double gpa)
{
  Student s;
  s.name = name;
  s.level = level;
  s.major = major;
  s.gpa = gpa;

  s.id = assignID("student");

  TreeNode<Faculty> *temp;

  temp = assignAdvisor();

  if(temp != NULL)
  {
    ListNode<unsigned int> *curr;
    curr = temp->key.students.front;

    cout << endl << "Adding student to faculty list: " << s.id << endl;

    cout << "NAME:" << temp->key.name << endl;
    //this is where it sometimes adds random students
    temp->key.students.insertFront(s.id);

    s.advisor = temp->key.id;
    studentTable.insert(s);
    cout << "ID assigned: " << s.id << ", Advisor assigned: " << s.advisor << endl;

    curr = temp->key.students.front;
    cout << "Printing students: " << endl;
    while (curr != NULL)
    {
      cout << curr->data << endl;
      curr = curr->next;
    }
  }
  else
  {
    cout << "Unable to insert student. Please add an advisor first." << endl;
    return false;
  }



  return true;
}

bool Database::addFaculty(string name, string level, string department)
{
  Faculty f;
  f.name = name;
  f.level = level;
  f.department = department;

  f.id = assignID("faculty");

  facultyTable.insert(f);



  return true;
}

//TODO
bool Database::run(int userInput)
{

  switch(userInput)
  {
    case 16://reprint all the options
    {
      printOptions();
      return true;
    }

    case 1://Print all students and their information (sorted by ascending id #)
    {
      cout << "\nOption: Print all students and their information (sorted by ascending id #)" << endl;

      if (studentTable.printTree(1) == "")
      {
        cout <<"No students in Database to display" << endl;
      }
      cout << studentTable.printTree(1) << endl;

      return true;
    }
    case 2:
    {
      cout << "\nOption: Print all faculty and their information (sorted by ascending id #)" << endl;
      cout << facultyTable.printTree(1) << endl;
      return true;
    }

    case 3:
    {
      cout << "\nOption: Find and display student information given the students id" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      printStudents(atoi(in.c_str()));
      return true;
    }

    case 4:
    {
      cout << "\nOption: Find and display faculty information given the faculty id" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      printFaculty(atoi(in.c_str()));
      return true;
    }
    case 5://Given a student’s id, print the name and info of their faculty advisor
    {
      cout << "\nOption: Given a student’s id, print the name and info of their faculty advisor" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      printAdvisor(atoi(in.c_str()));
      return true;
    }

    case 6://Given a faculty id, print ALL the names and info of his/her advisees.
    {
      cout << "\nOption: Given a faculty id, print all the names and info of his/her advisees" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      printAdvisees(atoi(in.c_str()));
      return true;
    }
    case 7://Add student
    {
      cout << "\nOption: Add student." << endl;
      string name;
      string level;
      string major;
      string gpa;

      cout << "Student name: " << endl;
      getline(cin, name);
      cout << "Student grade level: " << endl;
      getline(cin, level);
      cout << "Student major:" << endl;
      getline(cin, major);
      cout << "Student GPA:"<< endl;
      getline(cin, gpa);
      if (name.length() > 0 && level.length() > 0 && major.length() > 0 && gpa.length() > 0)
      addStudent(name, level, major, atof(gpa.c_str()));

      else
      cout << "Invalid entry." << endl;
      return true;
    }

    case 8://delete student
    {
      cout << "\nOption: Delete a student given the id" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      deleteStudent(atoi(in.c_str()));
      return true;
    }

    case 9://Add a new faculty member
    {
      cout << "\nOption: Add faculty." << endl;
      string name;
      string level;
      string department;


      cout << "Faculty name: " << endl;
      getline(cin, name);
      cout << "Faculty level: " << endl;
      getline(cin, level);
      cout << "Faculty department:" << endl;
      getline(cin, department);


      if (name.length() > 0 && level.length() > 0 && department.length() > 0)
      addFaculty(name, level, department);

      else
      cout << "Invalid entry." << endl;

      return true;
    }

    case 10://delete faculty member
    {
      cout << "\nOption: Delete a Faculty member given the id" << endl;
      cout << "What is the id?" << endl;
      string in;
      getline (cin, in);
      deleteFaculty(atoi(in.c_str()));
      return true;
    }

    case 11://Change a student’s advisor given the student id and the new faculty id
    {
      cout << "\nOption: Change a student’s advisor given the student id and the new faculty id" << endl;
      cout << "What is the student id?" << endl;
      string in1;
      getline (cin,in1);
      cout << "What is the faculty id?" << endl;
      string in2;
      getline (cin, in2);
      changeAdvisor(atoi(in1.c_str()), atoi(in2.c_str()));
      return true;
    }

    case 12://Remove an advisee from a faculty member given the ids
    {
      cout << "\nOption: Remove an advisee from a faculty member given the ids (reassign the student)" << endl;
      cout << "What is the student id?" << endl;
      string in1;
      getline (cin,in1);
      cout << "What is the faculty id?" << endl;
      string in2;
      getline (cin, in2);
      removeAdvisee(atoi(in1.c_str()), atoi(in2.c_str()));
      return true;
    }

    case 13://Rollback (undo)
    {
      cout << "\nOption: Rollback" << endl;
      cout << "Disclaimer: this doesnt work :(" << endl;
      //rollBack();
      return true;
    }

    case 14: //delete ALL
    {
      studentTable.deleteAll();
      facultyTable.deleteAll();


      cout << "Deleted all..." << endl;

      return true;
    }

    case 15://Exit
    {
      return false;
    }

  }

  cout << "Please input a valid option number. Type '16' to see the options again" << endl;
  return true;
}

void Database::printOptions()
{
  cout << "What would you like to do?\n" <<endl;

  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Delete all entries" << endl;
  cout << "15. Exit" << endl;
  cout << "16. Reprint all the options" << endl << endl;
}

TreeNode<Faculty>* Database::assignAdvisor()
{
  if (facultyTable.isEmpty())
  {
    cout << "Faculty Table is empty." << endl;
    return NULL;
  }
  else
  {
    cout << "Selecting random faculty..." << endl;
    //add facultyTable into an array and picking  from random
    unsigned int idx = rand()%facultyTable.getSize();
    return facultyTable.getKey(idx);
  }
}

bool Database::saveToFile(string fileName)
{
  //using preorder traversal
  ofstream myFile;
  myFile.open(fileName.c_str(), ios::out | ios::binary | ios::trunc);
  if(myFile.is_open())
  {
    myFile << "Student" << endl;
    myFile << studentTable.printTree(2);
    myFile << "Faculty" << endl;
    myFile << facultyTable.printTree(2);
    myFile.close();
    return true;
  }
  else
  {
    cout << "Unable to open file" << endl;
    return false;
  }
}

bool Database::loadFromFile(string fileName)
{
  ifstream myFile;
  myFile.open(fileName.c_str(), ios::in | ios::binary);
  if (myFile.is_open())
  {
    string line;
    bool is_student = false;
    while (getline(myFile, line))
    {
      if (line == "Student")
      {
        is_student = true;
      }
      else if (line == "Faculty")
      {
        is_student = false;
      }
      else if (is_student && line.length() > 0)  //Loading only the lines after "Student"
      {
        string userInput[6];
        int l_idx = 0;
        for (int i = 0; i < line.length(); ++i)
        {
          if(line[i] == '|')
          {
            ++l_idx;
            ++i;
          }
          userInput[l_idx] += line[i];
        }
        Student l_s(userInput[1], userInput[2], userInput[3], atof(userInput[4].c_str()), atoi(userInput[0].c_str()));
        l_s.advisor = atoi(userInput[5].c_str());
        studentTable.insert(l_s);
      }
      else if(line.length() > 0) //Loading lines after "Faculty"
      {
        DoublyLinkedList<string> userInput;
        string temp = "";
        for (int i = 0; i < line.length(); ++i)
        {
          if(line[i] == '|')
          {
            userInput.insertBack(temp);
            temp = "";
            ++i;
          }
          temp += line[i];
        }
        userInput.insertBack(temp);

        if(userInput.getSize() >= 4)
        {
          Faculty l_f(userInput.front->next->data, userInput.front->next->next->data, userInput.front->next->next->next->data, atoi(userInput.front->data.c_str()));
          ListNode<string>* curr;
          curr = userInput.front->next->next->next->next;

          while (curr != NULL)
          {
            l_f.students.insertBack(atoi(curr->data.c_str()));
            curr = curr->next;
          }
          facultyTable.insert(l_f);

        }
      }
    }

    myFile.close();
    return true;
  }
  else
  {
    cout << "Unable to open file" << endl;
    return false;
  }
}

bool Database::printStudents(unsigned int id)
{
  Student temp;
  temp.id = id;
  TreeNode<Student> *temp2;
  temp2 = studentTable.find(temp);
  if (temp2 != NULL)
  {
    cout << temp2->key << endl;
  }
  else
  {
    cout << "Student record does not exist." << endl;
  }
}

bool Database::printFaculty(unsigned int id)
{
  Faculty temp;
  temp.id = id;
  TreeNode<Faculty> *temp2;
  temp2 = facultyTable.find(temp);
  if (temp2 != NULL)
  {
    cout << temp2->key << endl;
  }
  else
  {
    cout << "Faculty record does not exist." << endl;
  }
}

bool Database::printAdvisor(unsigned int id)
{
  Student s_temp;
  s_temp.id = id;


  if (!studentTable.contains(s_temp))
  {
    cout << "That sucks" << endl;
    return false;
  }

  TreeNode<Student> *s_temp2;
  s_temp2 = studentTable.find(s_temp);



  Faculty f_temp;
  f_temp.id = s_temp2->key.advisor;

  TreeNode<Faculty> *f_temp2;
  f_temp2 = facultyTable.find(f_temp);
  if (f_temp2 != NULL)
  {
    cout << f_temp2->key << endl;
  }
  else
  {
    cout << "Student does not have a faculty advisor." << endl;
  }
}

bool Database::printAdvisees(unsigned int id)
{


  Faculty f_temp;
  f_temp.id = id;

  if (!facultyTable.contains(f_temp))
  {
    cout << "That sucks" << endl;
    return false;
  }

  ListNode<unsigned int> *curr;

  curr = facultyTable.find(f_temp)->key.students.front;
  while (curr != NULL)
  {
    printStudents(curr->data);
    curr = curr->next;
  }
}

bool Database::deleteStudent(unsigned int id)
{
  Student s_temp;
  s_temp.id = id;

  Faculty f_temp;
  TreeNode<Faculty> *f_temp2;

  TreeNode<Student> *s_temp2;
  s_temp2 = studentTable.find(s_temp);


  if(s_temp2 != NULL)
  {
    //remove id from advisor's advisee list
    f_temp.id = s_temp2->key.advisor;
    f_temp2 = facultyTable.find(f_temp);



    if( f_temp2->key.students.front == NULL)

    f_temp2->key.students.remove(s_temp.id);


    //removing from Tree
    studentTable.deleteNode(s_temp);


  }
  else
  {
    cout << "THis thing is not exist" << endl;
  }

}

bool Database::deleteFaculty(unsigned int id)
{
  Faculty f_temp;
  f_temp.id = id;
  TreeNode<Faculty> *f_temp2;

  if (!facultyTable.contains(f_temp))
  {
    cout << "The faculty does not exist" << endl;
    return false;
  }

  f_temp2 = facultyTable.find(f_temp);

  Student s_temp;
  TreeNode<Student> *s_temp2;


  TreeNode<Faculty>* newAdvisor;

  ListNode<unsigned int>* curr = f_temp2->key.students.front;

  if (facultyTable.getSize() <= 1)
  {
    cout << "Unable to remove faculty. At least one faculty member required." << endl;
    return false;
  }

  while (curr != NULL)
  {
    s_temp.id = curr->data;
    do
    {
      s_temp2 = studentTable.find(s_temp);
      newAdvisor = assignAdvisor();
      s_temp2->key.advisor = newAdvisor->key.id;
      newAdvisor->key.students.insertFront(curr->data);
    }while (f_temp2->key == newAdvisor->key);
    curr = curr->next;
  }

  facultyTable.deleteNode(f_temp);



  return true;
}

bool Database::changeAdvisor(unsigned int studentId, unsigned int facultyId)
{
  Student s_temp;
  s_temp.id = studentId;
  if (!studentTable.contains(s_temp))
  {
    cout << "The student ID does not exist." << endl;
    return false;
  }
  Faculty f_temp;
  f_temp.id = facultyId;
  if (!facultyTable.contains(f_temp))
  {
    cout << "The faculty ID does not exist" << endl;
    return false;
  }

  //remove student id from old advisor
  TreeNode<Student> *s_temp2 = studentTable.find(s_temp);
  Faculty old_advisor;
  old_advisor.id = s_temp2->key.advisor;
  facultyTable.find(old_advisor)->key.students.remove(studentId);

  //set new advisor
  s_temp2->key.advisor = facultyId;
  facultyTable.find(f_temp)->key.students.insertFront(studentId);



  return true;
}

bool Database::removeAdvisee(unsigned int studentId, unsigned int facultyId)
{
  Student s_temp;
  s_temp.id = studentId;
  if (!studentTable.contains(s_temp))
  {
    cout << "The student ID does not exist." << endl;
    return false;
  }
  Faculty f_temp;
  f_temp.id = facultyId;
  if (!facultyTable.contains(f_temp))
  {
    cout << "The faculty ID does not exist" << endl;
    return false;
  }

  if (facultyTable.getSize() <= 1)
  {
    cout << "Unable to reassign student. Requires at leaset 2 faculty." << endl;
    return false;
  }
  unsigned int newAdvisor;
  do {
    newAdvisor = assignAdvisor()->key.id;
    changeAdvisor(studentId, newAdvisor);
  } while(newAdvisor == facultyId);



  return true;
}

bool Database::rollBack()
{
  if (currentSave <= 0)
  {
    cout << "Unable to rollback." << endl;
    return false;
  }

  studentTable.deleteAll();
  facultyTable.deleteAll();

  stringstream ss;
  ss << currentSave;
  loadFromFile(ss.str());
  --currentSave;

}
