#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

class Identity
{
public:
    //构造函数
    Identity(const char Name[32], string Number );
    //复制构造函数
    Identity(const Identity& i);
    //析构函数
    ~Identity() {cout << "Identity: distructor" << endl;}
    //身份证号的存入函数
    void setnumber();
    //名字的存入函数
    void setname();
    //身份证号的取出函数
    string getnumber() { return number_; }
    //名字的取出函数
    char* getname() { return name_; }
    //打印身份信息函数
    void show();
private:
    //考虑到有的身份证号有字母，因此身份证号用string类型
    string number_ = "000000000000000000";        
    char name_[32] = "无名氏";
};

Identity::Identity(const char Name[32]="无名氏", string Number = "000000000000000000") :number_{ Number }
{
    //运用字符串函数strcpy_s进行名字的初始化
    strcpy_s(name_,strlen(Name)+1,Name);
    cout << "Identity: constructor" << endl;
}

Identity::Identity(const Identity& i) :number_{ i.number_ }
{
    strcpy_s(name_, strlen(i.name_) + 1, i.name_);
    cout << "Identity: copy constructor" << endl;
}

void Identity::setnumber()
{
    cout << "Enter ID number:";
    cin >> number_;
}

void Identity::setname()
{
    cout << "Enter name:";
    cin >> name_;
}

void Identity::show()
{
    cout << "name:" << name_ << "\tID number:" << number_ << endl;
}




class Student
{
public:
    //构造函数
    Student(Identity i, string s);
    //复制构造函数
    Student(const Student& s);
    //析构函数
    ~Student() { cout << "Student: distructor" << endl; }
    //id的存入函数
    void setid();
    //学校的存入函数
    void setschool();
    //id的取出函数
    Identity getid() { return id_; };
    //学校的取出函数
    string getschool() { return school_; };
    //打印学生身份信息及学校的函数
    void show();

private:
    Identity id_;
    string school_="中山大学";
};



Student::Student(Identity i, string s = "中山大学") :id_{ i }, school_{ s }
{
    cout << "Student：constructor" << endl;
}


Student::Student(const Student& s) :id_{ s.id_ }, school_{s.school_}
{
    cout << "Student: copy constructor" << endl;
}


void Student::setid()
{
    id_.setname();
    id_.setnumber();

}

void Student::setschool()
{
    cout << "Enter the school of student：";
    cin >> school_;

}


void Student::show()
{
    cout << "School：" << school_ << "\t";
    id_.show();
}



//同样考虑到身份证号中字母的因素，因此改为string型
Student MakeStudent(string number, const char* name, std::string school)    
{
    Identity Stu1(name,number);
    //为避免复制构造，因此直接返回Student的类
    return Student(Stu1, school);
}



int main()
{
    //调用Identity的默认构造函数
    Identity person1,person2("李华","123456789123456789");
    //调用Identity的复制构造函数
    Identity person3(person2);
    //调用Identity的show()函数
    person1.show();
    person2.show();
    person3.show();
    //战术分隔，使输出界面更分明
    cout << endl;

    //调用Identity的存入名字和存入身份证号的函数
    person1.setname();
    person1.setnumber();
    cout << "name:" << person1.getname() << "\tID number:" << person1.getnumber() << endl;
    //战术分隔，使输出界面更分明
    cout << endl;

    //调用Student的构造函数
    Student pupil_1(person1);
    //调用Student的复制构造函数
    Student pupil_2(pupil_1);
    //调用Student的show()函数
    pupil_1.show();
    pupil_2.show();
    //战术分隔，使输出界面更分明
    cout << endl;


    //调用Student的存入id和存入学校函数
    pupil_1.setid();
    pupil_1.setschool();
    //战术分隔，使输出界面更分明
    cout << endl;


    Identity person4 = pupil_1.getid();
    cout << "School：" << pupil_1.getschool() << "\t";
    person4.show();
    //战术分隔，使输出界面更分明
    cout << endl;


    //调用MakeStudent函数
    Student pupil_3 = MakeStudent("666555444333222111","林俊杰","清华大学");
    pupil_3.show();
   

    cout << endl;
    return 0;

}

