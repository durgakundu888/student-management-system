#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
        int rollno, age;
        string name;
    public:
        Student(int studRollno, int studAge, string studName){
            rollno = studRollno;
            name = studName;
            age = studAge;
        }
        void setRollno(int studRollno) {
            rollno = studRollno;
        }
        int getRollno() {
            return rollno;
        }
        void setName(string studName) {
            name = studName;
        }
        string getName() {
            return name;
        }
        void setAge(int studAge) {
            age = studAge;
        }
        int getAge() {
            return age;
        }
        void displayStudent() {
            cout<<"\t\tRoll No : "<<rollno<<endl;
            cout<<"\t\tName :"<<name<<endl;
            cout<<"\t\tAge :"<<age<<endl;
        }
};
void updateStudent(vector<Student>& students){
    string sname;
    bool found = false;
    int choice;
    cout<<"\t\tEnter Name To Update Record :";
    cin.ignore();
    getline(cin,sname);
    for(int i = 0; i <students.size();i++) {
        if(students[i].getName()==sname) {
            found = true;
            cout<<"\t\t------- Student Found -------"<<endl;
            cout<<"\t\t 1. Update Rollno "<<endl;
            cout<<"\t\t 2. Update Name "<<endl;
            cout<<"\t\t 3. Update Age "<<endl;
            cout<<"\t\tEnter Your Choice :";
            cin>>choice;

            switch(choice){
                case 1: {
                    int rno;
                    cout<<"\t\tEnter New Rollno :";
                    cin>>rno;
                    students[i].setRollno(rno);
                    break;
                }
                case 2: {
                    string name;
                    cout<<"\t\tEnter New Name :";
                    cin.ignore();
                    getline(cin,name);
                    students[i].setName(name);
                    break;
                }
                case 3: {
                    int age;
                    cout<<"\t\tEnter New Age :";
                    cin>>age;
                    students[i].setAge(age);
                    break;
                }
                default:
                    cout<<"\t\tInvalid Number"<<endl;
            }
            return;
        }
    }
    cout<<"\t\tRecord Not Found Here"<<endl;
    return;
}
void SearchStudent(vector<Student>& students){
    int rollno;
    cout<<"\t\tEnter Rollno :";
    cin>>rollno;
    for(int i = 0; i<students.size();i++){
        if(students[i].getRollno() == rollno){
            cout<<"\t\t------------ Student Found ----------"<<endl;
            students[i].displayStudent();
            return;
        }
    }
}
void DisplayAllStudent(vector<Student>& students){
    if(students.empty()){
        cout<<"\t\t No Student Found "<<endl;
        return;
    }
    for(int i = 0; i < students.size(); i++) {
        students[i].displayStudent();
        cout<<endl;
    }
}
void addNewStudent(vector<Student> &students){
    int rollno, age;
    string name;
    cout<<"\t\tEnter Rollno :";
    cin>>rollno;
    for(int i=0; i<students.size();i++){
        if(students[i].getRollno()==rollno){
            cout<<"\t\tStudent Already Exists..."<<endl;
            return;
        }
    }
    cout<<"\t\tEnter Name :";
    cin>>name;
    cout<<"\t\tEnter Age :";
    cin>>age;

    Student newStudent(rollno,age,name);
    students.push_back(newStudent);

    cout<<"\t\tStudent Successfully Added..."<<endl;
}
void deleteStudent(vector<Student>& students){
    string name;
    cout<<"\t\tEnter Name To Delete :";
    cin.ignore();
    getline(cin,name);
    for(int i = 0; i < students.size(); i++) {
        if(students[i].getName() == name) {
            students.erase((students.begin()+i));
            cout<<"\t\tStudent Removed Successfully"<<endl;
        }
    }
    return;
}
int main(){
    vector<Student> students;
    students.push_back(Student(1, 25, "Zaya Battogtokh"));
    students.push_back(Student(2, 25, "Soukarya Ghosh"));
    students.push_back(Student(3, 26, "Vishakha Sehgal"));
    students.push_back(Student(4, 25, "Ryan Bloom"));
    students.push_back(Student(5, 25, "Peace Pius"));
    students.push_back(Student(6, 25, "Ribka Tewelde"));
    students.push_back(Student(7, 25, "John Naylor"));
    students.push_back(Student(8, 25, "Darren Chan"));
    students.push_back(Student(9, 25, "James Yun"));
    students.push_back(Student(10, 25, "Rasha Hantash"));
    students.push_back(Student(11, 25, "Diana Calderon"));
    students.push_back(Student(12, 25, "Minhaz Abdullah"));
    students.push_back(Student(13, 26, "Prashant Bishwakarma"));
    char choice;
    do{
        system("cls");
        int op;
        cout<<"\t\t----------------------------"<<endl;
        cout<<"\t\tStudent Management System"<<endl;
        cout<<"\t\t----------------------------"<<endl;
        cout<<"\t\t 1. Add New Student"<<endl;
        cout<<"\t\t 2. Display All Students"<<endl;
        cout<<"\t\t 3. Search Student"<<endl;
        cout<<"\t\t 4. Update Student"<<endl;
        cout<<"\t\t 5. Delete Student"<<endl;
        cout<<"\t\t 6. Exit"<<endl;
        cout<<"\t\tEnter Your Choice : ";
        cin>>op;
        switch(op){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                exit(1);
            default:
                cout<<"\t\tInvalid Number ...."<<endl;
        }
        cout<<"\t\tDo You Want To Continue [Yes / No] ? :";
        cin>>choice;
    } while(choice=='y'||choice=='Y');

}