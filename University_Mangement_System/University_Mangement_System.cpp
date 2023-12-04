#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Department {
private:
 string name;
 int capacity;
 double requiredGpa;
public:
 Department() {
 }
 Department(string n, int c, double r) {
  name=n;
  capacity=c;
  requiredGpa=r;
 }
 void setName(string n) {
  name = n;
 }
 string getName() {
  return name;
 }
 void setCapacity(int c) {
  capacity = c;
 }
 int getCapacity() {
  return capacity;
 }
 void setRequiredGpa(int r) {
  requiredGpa = r;
 }
 double getRequiredGpa() {
  return requiredGpa;
 }
 
};


class Person {
protected:
 string name;
 char gender;
 int id;
 int age;
public:
 Person() {}
 Person(string name, char gender, int id , int age) {
  this->name=name;
  this->gender = gender;
  this->id=id;
  this->age=age;
 }
 void setName(string n) {
  name = n;
 }
 string getName() {
  return name;
 }
 void setGender(char g) {
  gender = g;
 }
 char getGender() {
  return gender;
 }
 void setAge(int a) {
  age = a;
 }
 int getAge() {
  return age;
 }
 void setId(int i) {
  id = i;
 }
 int getId() {
  return id;
 }
};


class Student :public Person{
private:
 int studectID;
 float studentGPA;
 int studentLevel;

public:
 Student() {};
 //parameterized constructor    
 Student(int id, string name , int studentLev,char gender, int age ,  double studentGpa) {
  studentGPA = studentGpa;
  studentLevel = studentLev;

  setName(name);
  setGender(gender);
  setAge(age);
  setId(id);
 };

 //set Information of student
 void setStudentGPA(float gpa) {
  studentGPA = gpa;
 }
 void setStudentLevel(int lev) {
  studentLevel = lev;
 }

 //get info about student
 int   getstudectID() {
  return studectID;
 }
 float getstudentGPA() {
  return studentGPA;
 }
 int  getstudentLevel() {
  return studentLevel;
 }

};


class Prof : public Person{
private:
 string profDegree;
 int profID;
 int profSalary;
 Department *d1;

public:
 Prof() {}
 //parameterized constructor
 Prof(int id ,  string name , int age , char gender ,Department *d1 ,  int profSal , string profDeg):Person( name , gender ,  id ,  age ) {
  profDegree = profDeg;
  profSalary = profSal;

 }

 //set Information of professor
 void setD1(Department *d1){
  this->d1 = d1 ; 
 }
 Department* getD1(){
   return d1 ; 
 }
 void setProfDegree(string profDeg) {
  profDegree = profDeg;
 }
 void setProfsalary(int profSal) {
  profSalary = profSal;
 }

 //get info about professor
 string getProfDegree() {
  return profDegree;
 }
 int  getProfID() {
  return profID;
 }
 int  getProfsalary() {
  return profSalary;
 }
};


class Course {
private:

 vector<Course*> prerequisites;
 vector<Student*> students;
 string name, courseCode;
 int courseHours;
 Prof *professor;

public:

 //default const
 Course() {}
 // parametrized const
 Course(string name , string courseCode, int courseHours ,vector<Course*> prerequisites  , Prof *professor ,  vector<Student*> students) {

this->name = name;
  this->professor = professor;
  this->courseHours = courseHours;
  this->courseCode = courseCode;
   this->students = students;
  this->prerequisites = prerequisites;

 }
void setP1(Prof *p1){
  this->professor=p1;
}
Prof *getProf(){
   return professor ;  
}
 // name 
 void setName(string name) {
  this->name = name;
 }
 string getName() {
  return name;
 }

 //professor
 void setProfessor(Prof* professor) {
  this->professor = professor;
 }
 Prof* getProfessor() {
  return professor;
 }

 //course hours 
 void setCourseHours(int courseHours) {
  this->courseHours = courseHours;
 }
 int getCourseHours() {
  return courseHours;
 }

 //course code 
 void setCourseCode(int courseCode) {
  this->courseCode = courseCode;
 }
 string getCourseCode() {
  return courseCode;
 }

};


class University {
private:
 static University* ptr;
 University() {
    addData();
 }
 vector <Student> studentList;
 vector <Prof> professorList;
 vector<Course> courses;
 vector<Department>departments;
 vector<Person>Persons;

public:
 University(const University& obj) = delete;
 static University* getInstance() {
  if (ptr == NULL)
   ptr = new University();
  return ptr;
 }
 void addDepartment(string name, int capacity, double requiredGpa) {
  bool ch = 0;
    for (int i = 0;i < departments.size();i++) {
   if (departments[i].getName() == name) {
    ch = 1;
    break;
   }
  }
  Department d( name, capacity, requiredGpa);
  if (ch) {
   cout << "Exist";
  }
  else departments.push_back(d);
 }
 bool updateDepartmentGpa(string Deptname,double gpa) {
  bool ch = 0; 
  for (int i = 0;i < departments.size();i++) {
   if (departments[i].getName() == Deptname) {            
    departments[i].setRequiredGpa(gpa);
    ch=1;
    return 1;
   }
  }
  if(!ch) {
   cout << "Invalid department name.";
   return 0;
  }
 }
 bool removeDepartment(string Deptname) {
   bool ch=0;
  for (int i = 0;i < departments.size();i++) {
   if (departments[i].getName() == Deptname) {    
    departments.erase(departments.begin() + i);
    ch=1;
    return 1;
   }
  }
  if(!ch) {
   cout << "not exist." << endl;
   return 0;
  }
 }
 bool AddCourse(string name, Prof *professor, int courseHours, string courseCode, vector<Student*> students, vector<Course*> prerequisites) {
  if (courseHours > 0 ) {
   Course c1( name ,  courseCode,  courseHours, prerequisites, professor, students);
   courses.push_back(c1);
   return true;
  }
  else {
   return false;
  }

 }

 // update functions 
 bool updateCourse(string courseCode, int courseHours) {
   bool ch=0;
  for (int i = 0;i < courses.size();i++) {
   if (courses[i].getCourseCode() == courseCode) {    
    courses[i].setCourseHours(courseHours); 
    ch=1;
    return 1;
   }
  }
  if(!ch) {
   cout << "not exist." << endl;
   return 0;
  }
 }

 // delete functions 
 bool deleteCourse(string courseCode) {
  bool ch=0;
  for (int i = 0;i < courses.size();i++) {
   if (courses[i].getCourseCode() == courseCode) {    
    courses.erase(courses.begin() + i);
    ch=1;
    return 1;
   }
  }
  if(!ch) {
   cout << "not exist." << endl;
   return 0;
  }
  return ch;
 }

 void addStudent(int level, double GPA, string name, char gender, int age, int id) {
  Student stdObj(id , name , level , gender , age , GPA);

  studentList.push_back(stdObj);
 }
 void addProfessor(string degree, int salary, string name, char gender, int age, int id , Department *d1) {
  Prof profObj(id ,name ,age , gender , d1, salary ,  degree);
  professorList.push_back(profObj);
 }

 bool updateGPA(int Id, float newGPA) {
  bool check = true;
  for (int i = 0; i < studentList.size(); i++)
  {
   if (Id == studentList[i].getstudectID()) {
    studentList[i].setStudentGPA(newGPA);
    break;
   }
   else {
    check = false;
   }
  }
  return check;
 }
 bool updateSalrya(int Id, int newSalary) {
  bool check = true;
  for (int i = 0; i < professorList.size(); i++)
  {
   if (Id == professorList[i].getProfID()) {
    professorList[i].setProfsalary(newSalary);
    break;
   }
   else {
    check = false;
   }
  }
  return check;
 }

 bool deltStudent(int id) {
  bool check = true;
  for (int i = 0; i < studentList.size(); i++)
  {
   if (id == studentList[i].getstudectID()) {
    studentList.erase(studentList.begin() + i);
    break;
   }
   else {
    check = false;
   }
  }
  return check;
 }
 bool deltProf(int id) {
  bool check = true;
  for (int i = 0; i < professorList.size(); i++)
  {
   if (id == professorList[i].getProfID()) {
    professorList.erase(professorList.begin() + i);
    break;
   }
   else {
    check = false;
   }
  }
  return check;
 }

 void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        studentList.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        studentList.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        studentList.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        studentList.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        studentList.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        studentList.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        studentList.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        studentList.push_back(s8);

        Prof p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professorList.push_back(p1);
        Prof p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professorList.push_back(p2);
        Prof p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professorList.push_back(p3);
        Prof p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professorList.push_back(p4);
        Prof p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professorList.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
        
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].getName()<<endl;
        }
        for(int i=0; i<professorList.size(); i++)
        {
            cout<<"Professor Name: "<<professorList[i].getName()<<endl;
        }
        for(int i=0; i<studentList.size(); i++)
        {
            cout<<"Student Name: "<<studentList[i].getName()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].getName()<<endl;
        }
    }
};

University* University::ptr = NULL;

int main()
{
University *uni = University::getInstance();
    uni->printAll();
    uni->deleteCourse("Net521");
    uni->printAll();
 return 0;
}