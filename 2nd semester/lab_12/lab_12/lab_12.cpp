#include <iostream>
#include <memory>
#include <list>

class Student;
class Teacher
{
public:
	Teacher(const std::string name) : m_name(name)
	{
		//std::cout << m_name << " created\n";
	}

	~Teacher()
	{
		//std::cout << m_name << " destroyed\n";
	}

	Teacher(const Teacher& A) : m_name(A.m_name), m_students(A.m_students)
	{
		std::cout << "Copy Bar\n";
	}

	Teacher& operator=(const Teacher& A)
	{
		std::cout << "\nOperator = \n";

		return *this;
	}

	void addNewStudent(std::shared_ptr<Student>& stud) 
	{
		m_students.push_back(stud);
	}

	void getAllStudents() 
	{
		if (!m_students.empty()) 
		{
			std::cout << "Все студенты учителя " + m_name + ": " << std::endl;
			for (auto& stud : m_students)
			{
				std::cout << stud->getName() << std::endl; // не работает! доделать
			}
		}
		else 
		{
			std::cout << "Учитель " + m_name + "не имеет учеников" << std::endl;
		}
	}

	const std::string& getName() const 
	{ 
		return m_name; 
	}

	friend void partnerUp(std::shared_ptr<Teacher>& p1, std::shared_ptr<Student>& p2);


private:
	std::string m_name;
	std::list<std::shared_ptr<Student>> m_students;

};


class Student
{
public:
	Student(const std::string name) : stud_name(name)
	{
		//std::cout << stud_name << " created\n";
	}
	~Student()
	{
		//std::cout << stud_name << " created\n";

	}
	Student(const Student& A) : stud_name(A.stud_name), m_teacher(A.m_teacher)
	{
		std::cout << "Copy Bar\n";
	}

	Student& operator=(const Student& A)
	{
		std::cout << "\nOperator = \n";

		return *this;
	}

	const std::weak_ptr<Teacher>& getTeacher() const
	{ 
		return m_teacher; 
	}

	const std::string& getName() const 
	{ 
		return stud_name; 
	}

	friend void partnerUp(std::shared_ptr<Teacher>& p1, std::shared_ptr<Student>& p2);


private:
	std::string stud_name;
	std::weak_ptr<Teacher> m_teacher;
};



void partnerUp(std::shared_ptr<Teacher>& p1, std::shared_ptr<Student>& p2)
{
	p2->m_teacher = p1;
	p1->addNewStudent(p2);
}


int main()
{
	setlocale(LC_ALL, "Russia");
	auto teacher{ std::make_shared<Teacher>("Lucy") };
	auto student{ std::make_shared<Student>("Ricky_1") };
	auto student2{ std::make_shared<Student>("Ricky_2") };
	auto student3{ std::make_shared<Student>("Ricky_3") };

	//ricky->getName();

	partnerUp(teacher, student);
	partnerUp(teacher, student2);

	teacher->getAllStudents();

	return 0;

}
