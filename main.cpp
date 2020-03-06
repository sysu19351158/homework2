#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

class Identity
{
public:
    //���캯��
    Identity(const char Name[32], string Number );
    //���ƹ��캯��
    Identity(const Identity& i);
    //��������
    ~Identity() {cout << "Identity: distructor" << endl;}
    //���֤�ŵĴ��뺯��
    void setnumber();
    //���ֵĴ��뺯��
    void setname();
    //���֤�ŵ�ȡ������
    string getnumber() { return number_; }
    //���ֵ�ȡ������
    char* getname() { return name_; }
    //��ӡ�����Ϣ����
    void show();
private:
    //���ǵ��е����֤������ĸ��������֤����string����
    string number_ = "000000000000000000";        
    char name_[32] = "������";
};

Identity::Identity(const char Name[32]="������", string Number = "000000000000000000") :number_{ Number }
{
    //�����ַ�������strcpy_s�������ֵĳ�ʼ��
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
    //���캯��
    Student(Identity i, string s);
    //���ƹ��캯��
    Student(const Student& s);
    //��������
    ~Student() { cout << "Student: distructor" << endl; }
    //id�Ĵ��뺯��
    void setid();
    //ѧУ�Ĵ��뺯��
    void setschool();
    //id��ȡ������
    Identity getid() { return id_; };
    //ѧУ��ȡ������
    string getschool() { return school_; };
    //��ӡѧ�������Ϣ��ѧУ�ĺ���
    void show();

private:
    Identity id_;
    string school_="��ɽ��ѧ";
};



Student::Student(Identity i, string s = "��ɽ��ѧ") :id_{ i }, school_{ s }
{
    cout << "Student��constructor" << endl;
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
    cout << "Enter the school of student��";
    cin >> school_;

}


void Student::show()
{
    cout << "School��" << school_ << "\t";
    id_.show();
}



//ͬ�����ǵ����֤������ĸ�����أ���˸�Ϊstring��
Student MakeStudent(string number, const char* name, std::string school)    
{
    Identity Stu1(name,number);
    //Ϊ���⸴�ƹ��죬���ֱ�ӷ���Student����
    return Student(Stu1, school);
}



int main()
{
    //����Identity��Ĭ�Ϲ��캯��
    Identity person1,person2("�","123456789123456789");
    //����Identity�ĸ��ƹ��캯��
    Identity person3(person2);
    //����Identity��show()����
    person1.show();
    person2.show();
    person3.show();
    //ս���ָ���ʹ������������
    cout << endl;

    //����Identity�Ĵ������ֺʹ������֤�ŵĺ���
    person1.setname();
    person1.setnumber();
    cout << "name:" << person1.getname() << "\tID number:" << person1.getnumber() << endl;
    //ս���ָ���ʹ������������
    cout << endl;

    //����Student�Ĺ��캯��
    Student pupil_1(person1);
    //����Student�ĸ��ƹ��캯��
    Student pupil_2(pupil_1);
    //����Student��show()����
    pupil_1.show();
    pupil_2.show();
    //ս���ָ���ʹ������������
    cout << endl;


    //����Student�Ĵ���id�ʹ���ѧУ����
    pupil_1.setid();
    pupil_1.setschool();
    //ս���ָ���ʹ������������
    cout << endl;


    Identity person4 = pupil_1.getid();
    cout << "School��" << pupil_1.getschool() << "\t";
    person4.show();
    //ս���ָ���ʹ������������
    cout << endl;


    //����MakeStudent����
    Student pupil_3 = MakeStudent("666555444333222111","�ֿ���","�廪��ѧ");
    pupil_3.show();
   

    cout << endl;
    return 0;

}

