#include<iostream>
#include <string>
#pragma once             //防止头文件重复包含












//虚析构和纯虚析构
//语法 //虚析构 virtual ~类名(){}  //纯虚析构  virtual ~类名(){}=0;







////多态的使用
//using namespace std;
//class drink 
//{
//public:
//	virtual void shaoshui() = 0;
//	virtual void chongpao() = 0;
//	virtual void daoru() = 0;
//	virtual void jialiao() = 0;
//	void zhizuo()
//	{
//		shaoshui();
//		chongpao();
//		daoru();
//		jialiao();
//	}
//};
//class coffee :public drink    
//{
//	virtual void shaoshui()
//	{
//		cout << "饮水" << endl;
//	}
//	virtual void chongpao()
//	{
//		cout << "泡咖啡" << endl;
//	}
//	virtual void daoru()
//	{
//		cout << "倒入飞机杯" << endl;
//	}
//	virtual void jialiao()
//	{
//		cout << "加入糖" << endl;
//	}
//};
//void dowork(drink *abs)
//{
//	abs->zhizuo();
//	delete abs;
//}
//void test()
//{
//	dowork(new coffee);
//}
//int main()
//{
//	test();
//	return 0;
//}






//纯虚函数和抽象类
//父类的虚函数有时完全没用，此时需要纯虚函数
//当一个类中有了一个纯虚函数就是抽象类了
// 抽象类 1. 无法实例化对象
// 2.子类必须重写抽象类中的纯虚函数，不然也会变成抽象类
//纯虚函数格式                 //virtual 返回值 函数名 参数表 =0;       //virtual void sb()=0;   于子类中重写  virtual void sb(){};






//多态原理//空函数变成虚函数就变成了4个字节,是应为产生了虚函数表指针，指向虚函数表
//子类重写了父类的虚函数,子类的虚函数会替换成子类的虚函数地址
// 当父类的指针或引用指向子类时就发生了多态
//开闭原则，对拓展进行开放，对修改进行关闭
//多态好处  //1.组织结构清晰//2.可读性强 //3.对于前期后期以及拓展维护性高



 
////多态的基本语法
////多态被分为静态和动态      //动态多态 派生类 虚函数  //静态多态 函数重载 运算符重载
////地址早绑定，在编译阶段确定函数地址
////地址晚绑定，在运行阶段确定函数地址
////动态多态的使用
//using namespace std;
//class person
//{
//public:
//	 virtual void jiao()//在 函数前面加一个virtual就能变成一个虚函数,变成虚函数就可以晚绑定了
//	{
//		cout << "人叫" << endl;
//	}
//};
//class sb :public person           //1.有继承关系//2.子类要重写父类的虚函数,父类和子类都有相同的函数，各方面完全相同的函数，函数可以实现不同
//{
//public:
//	void jiao()
//	{
//		cout << "傻逼叫" << endl;
//	}
//};
//void doshuo(person &person)//动态多态满足条件//父类的指针或引用，执行子类对象
//{
//	person.jiao();
//}
//void test()
//{
//	sb sb1;
//	doshuo(sb1);
//}
//int main()
//{
//	test();
//	return 0;
//}




//棱形继承和解决
//多继承使用作用域来使其明确 
//利用虚继承可以解决棱形继承的问题,继承前面加关键字 virtual   //class sheep : virtual public person {}
//于是最上面的父类就叫虚基类     //此时来自两个父类的数据在其共同的子类中就不会不明确 可以直接使用  s.m_A
//vbptr  虚基类指针,指向虚基类表（vbtable）,两个父类的指针加上偏移量指向的是一个数据





//多继承语法
//允许一个儿子认多个爹 ,不建议使用
//语法  class son : public base1 , public base2





//继承同名静态成员的处理
//可以和下面一段一样来访问同名静态成员属性，但由于是静态的，也可以用类名直接访问 Base::m_A  通过子类到父类也行son::Base::m_A
//son::base::func()通过类名来访问,   s.base::m_A通过对象      ,




//继承同名成员处理方式
//同名成员属性的处理方式   //通过子类对象 访问父类同名成员时，需要加作用域   原来直接调用子类中的用 s.m_A // 访问父类 s.Base::m_A  base是父类的名称
//同名成员函数的处理
//直接调用也是调用子类中的成员，父类调用也是前面加类   //子类 s.func      //父类调用s.Base::func()
//当子类中有和父类同名的函数成员时，子类会隐藏父类中的同名，加作用域就可以访问到  




//构造和析构的顺序
//先构造父类，再构造子类，析构的顺序相反




//继承中的对象模型         
//父类中非静态成员属性都会保留下来，但是private中的会被隐藏起来，且访问不到




////继承方式
////公共继承  父类中保护和公共到子类不变，私有的无法访问
////保护继承  父类的保护和公共全变成保护，私有的访问不到   ，保护权限类外访问不到
////私有继承  父类的保护和公共全变成私有，私有访问不到




//继承  ,减少重复的代码
//using namespace std;
//class person
//{
//
//};
//class jb:public person         //继承的写法，此时jb类就继承了person的全部信息  //class 子类 : 继承方式 父类    //子类也叫派生类，父类也叫基类
//{
//
//};
//void test()
//{
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//





//函数调用运算符（）的重载，重载后非常像函数，被称为仿函数
//void operator ()(string test)
//{
//	cout << string << endl;
//}
//class add 
//{
//public:
//	int operator()(int a, int b)      // 重载方式
//	{
//		return a + b;
//	}
//
//};
//void test()
//{
//	add myadd;
//	int ret = myadd(10, 20);
//}
//int main()
//{
//	test();
//	return 0;
//}





////关系运算符重载    可以让两个自定义类型对象进行比较
//bool operator==(person &p)     //bool在c++中进行比较，相等输出  return true 不相等输出 return false
//{
//	if(this->m_ Age== p2.m_Age && this->m_name ==p2.m_name);
//	return true;
//	return false;
//}
//p1 == p2;




////赋值运算符重载
//using namespace std;
//class person
//{
//public:
//	person(int A)
//	{
//		m_A = new int(A);
//	}
//	~person()           //切勿使内存重复释放
//	{
//		if (m_A != NULL)
//		{
//			delete m_A;
//			m_A = NULL;
//		}
//	}
//
//	person& operator=(person &p)  //返回的是引用，才是他的自身
//	{
//		
//		if (m_A != NULL)
//		{
//			delete m_A;
//			m_A = NULL;
//		}
//		m_A=new int(*p.m_A);   //深拷贝
//
//		return *this;                        //进行链式反应
//	}
//	int* m_A;
//};
//void test()
//{
//	person p1(18);
//	person p2(20);
//	person p3(30);
//	p1 = p2 = p3;
//	cout << *p1.m_A << endl;
//	cout << *p2.m_A << endl;
//}
//int main()
//{
//	test();
//}





//前置递增运算符重载
//myinteger& operator++()         //返回引用是为了对一个数据进行递增操作
//{
//	m_mun++;
//	return *this;         //将自身作为返回
//}
//void test()
//{
//	myinteger myint;
//	cout << ++myint << endl;
//}
//后置重载         后置递增返回的是值，前置递增返回的一定是引用
//myinteger operator++(int)   //int 是一个占位参数，用于区分前置和后置,
//{
//    myinteger tmep=*this;   //先记录自身当时的结果
//	  tmep++;                  //在递增
//	  return temp;            //最后再返回
//}





////左移运算符重载       可以输出自定义数据类型 
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person& p);              //使用友元使得<<运算符重载得以访问私有
//	//                              不会实现成员函数重载<<运算符
//public:
//	int m_A;
//	int m_B;
//};
////只能用的全局函数重载<<运算符
//ostream& operator<<(ostream&  cout,person &p)   //cout属于ostream 类中的  ,前面使用ostream类可以接受返回值，使得链式输出得以执行
//{
//	cout << p.m_A << p.m_B;
//	return cout;
//}
//void test()
//{
//	person p;
//	p.m_A=10;
//	p.m_B=20;
//	cout << p.m_A << endl;    //cout 是一个输出流     *对象*
//	cout << p<<endl;
//}
//int main()
//{
//	test();
//}




////+运算符自己操作
//using namespace std;
//class person
//{
//public:
//	person operator+(person& p2)
//	{
//		person temp;
//		temp.m_B = this->m_B - p2.m_B;          //甚至可以用加号运算符变成减法,所以说别滥用，会被打死
//		return temp;
//	}
//
//	int m_A;
//	int m_B;
//};
//void test()
//{
//	person p1;
//	p1.m_B = 10;
//	person p2;
//	p2.m_B = 20;
//	person p3 = p1 + p2;
//	cout << p3.m_B << endl;       
//}
//int main()
//{
//	test();
//	return 0;
//}





////重载，对已有的运算符进行重新定义，赋予另一种功能，以适应不同数据类型
//using namespace std;
//class person
//{
//public:
//	//person operator+(person& p)         //使用operator  ,成员函数就传一个就行了  ,全局函数就传两个参数相加   //本质是   person p3 = p1.operator + (p2)
//	//{
//	//	person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//	int m_A;
//	int m_B;
//};
//person operator+(person& p1, person& p2)           //全局函数的+运算符的重载
//{
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p2.m_B + p1.m_B;
//	return temp;
//}                                     //修改参数为person &p1,int num   也可以实现和整数的+重载运算
//void test1()
//{
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 20;
//	person p2;
//	p2.m_A = 30;
//	p2.m_B = 40;
//
//	person p3 = p1 + p2;   //重载后的运算   //本质是    person p3 = operator + (p1,p2)
//	cout <<p3.m_A<< endl;
//	cout << p3.m_B << endl;
//}                                           
//int main()
//{
//	test1();
//	return 0;
//}                     //对于内置类型数据的表达式是不可以更改的    ，不要滥用运算符重载





//friend void func();       成员函数友元
//friend void goodgay::func(fnagzi *fnagzi1);   全局友元
//friend class today;          友元类





////成员函数做友元
//using namespace std;
//class building;
//class goodgay
//{
//public:
//	goodgay();
//	void visit();
//	void visit2();
//	building* building1;                 //创建一个指向building类的指针，指针的名字叫做  building1
//};
//class building
//{
//	friend void goodgay::visit2();         //与全局函数的区别在于前面声明了是goodgay中的函数         //关键
//public: 
//	building();
//	string m_keting;
//private:
//	string m_woshi;
//
//};
//building::building()
//{
//	m_keting = "客厅";
//	m_woshi = "卧室";
//
//}
//goodgay::goodgay()
//{
//	building1 = new building;
//}
//void goodgay::visit()
//{
//	cout << building1->m_keting << endl;
//}
//void goodgay::visit2()
//{
//	cout << building1->m_woshi<< endl;
//}
//void test1()
//{
//	goodgay gg;
//	gg.visit();
//	gg.visit2();
//}
//int main()
//{
//	test1();
//	return 0;
//}






////友元类
//using namespace std;
//class building
//{
//	friend class goodgay;    //使可以访问私有成员               //关键
//public:
//	building();
//	string m_keting;
//private:
//	string m_woshi;
//};
//class goodgay
//{
//public:
//	goodgay();
//	void visit();
//	building* building1;
//	int m_A;
//};
//goodgay::goodgay()
//{
//	building1 =new building;
//}
//building::building()
//{
//	m_keting = "客厅";
//	m_woshi = "卧室";
//}
//void goodgay::visit()
//{
//	cout << "好基友正在访问:" << building1->m_keting << endl;
//	cout << "好基友正在访问:" << building1->m_woshi << endl;
//}
//void test1()
//{
//	goodgay gg;
//	gg.visit();
//}
//int main()
//{
//	test1();
//	return 0;
//}





////友元,全局函数做友元函数
//using namespace std;
//class fangzi
//{
//	friend void test(fangzi* fangzi1);     //使用友元在此处声明                     //关键
//
//public:
//	fangzi()
//	{
//		string keting = "客厅";
//		string woshi = "卧室";
//	}
//public:
//	string keting;  
//private:
//	 string woshi;
//};
//void test(fangzi* fangzi1)
//{
//	cout << "正在访问" << fangzi1->keting << endl;
//	cout << "正在访问" << fangzi1->woshi << endl;         //使得私有成员可以访问
//}
//void test2()
//{
//	fangzi fangzi1;
//	test(&fangzi1);
//}
//
//int main()
//{
//	test2();
//	return 0;
//}






////成员函数加const后成为常函数
////常函数内不可以修改成员属性
////成员属性声明时加关键字mutable，在常函数中依然可以修改
////void func() const 对，const加在后面
//using namespace std;
//class person
//{
//public:
//	void showperosn()const   //在成员函数后面加const修饰的是this指针,指向的值也不可以被修改
//	{
//		//this->m_A=100;           //this 的本质是指针常量，是不可以被修改指向的，但其指向的值是可以被修改的
//		this->m_B=100;   //前面加上mutable就可以被修改
//	}
//	int m_A;
//	mutable int m_B;
//};
//void test1()
//{
//	person p;
//	p.showperosn();
//}
//void test2()                      //常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
//{
//	const person p;  //对象前面加const，变成常对象
//	//p.m_A=100;   //此时不可以修改
//	p.m_B=100;    //此时可以修改
//}
//int main()
//{
//	//test1();
//	test2(); 
//	return 0;
//}





//空指针也可以访问成员函数，但是要注意this 的影响所有变量前面都会有   this->  




////this 指针指向被调用的成员函数所属的对象
////形参和成员变量同名时可以用this指针来区别
////在非静态成员函数中返回对象本身，使用return *this
//using namespace std;
//class person
//{
//public:
//	person(int age)
//	{
//		this->age = age;//若写成 age=age则无法,this可以解决名称冲突
//	}
//	person& add(person &p)
//	{
//		this->age+=p.age;   //this 指向p2的指针，而this指向的是对象的本体
//		return *this;     
//	}
//	int age;
//};
//void test()
//{
//	person p(18);//this 指针指向被调用的成员函数所属的对象  此时p1在调用
//	cout << p.age << endl;
//}
//void test2()
//{
//	person p1(10);
//	person p2(10);
//	p2.add(p1).add(p1).add(p1);    //上面调用时，如果是 person& add(person &p)则是用引用的方式返回，person add(person &p)就是以值的方式返回，前者可以叠加为40，后者只加一次，20
//	cout << p2.age << endl;
//}
//int main()
//{
//	test();
//	test2();
//	return 0;
//}





//编译器会为了空对象也分配     1     个字节的空间，为了区分空对象占内存的位置, 空对象也要有自己的地址
//成员变量和成员函数分开存储
//非静态成员变量  属于累的对象上
//非静态成员函数，静态成员变量和函数都不属于类的对象上






////静态成员函数
////1.所有对象共享同一个函数
////2.静态成员函数只能访问静态成员变量
//using namespace std;
//class person
//{
//public:
//	static void func()
//	{
//		m_A = 100;
//		//m_B = 200;   //非静态成员变量会在这里报错,无法区分是哪个对象的m_B
//		cout << "函数的调用" << endl;
//	}
//	static int m_A;
//	int m_B;
//};
//int person::m_A=0;
//void test()
//{
//	person p;
//	p.func();    //通过对象来访问
//	person::func();   //通过类名来访问
//}
//int main()
//{
//	test();
//	return 0;
//}






////静态成员变量,前面加上static
////1.所有对象共享一份数据
////2.在编译阶段分配内存
////3.类内声明，类外初始化
//using namespace std;
//class person
//{
//public:
//	static int m_A;
//private:
//	static int m_B;   //静态成员变量也是无法突破私有限制的
//};
//int person::m_A=100;   //类外初始化
//void test1()
//{
//	person p1;
//	cout << p1.m_A<<endl;
//	person p2;
//	p2.m_A = 200;
//	cout << p1.m_A << endl;   //修改p2导致p1也变成200，说明静态成员变量是所有对象共享的
//}
//void test2()
//{
//	cout << person::m_A << endl;//由于对象都共享，则不要对象，直接访问类名中的数据就行
//}
//int main()
//{
//	test1();
//	return 0;
//}






////类对象作为类成员
////后构造的先释放
//using namespace std;
//class phone
//{
//public:
//	phone(string phone)
//	{
//		m_B = phone;
//	}
//	phone(string a, string b) :m_A(a), m_B(b) 
//	{
//		;
//	};
//	string m_A;
//	string m_B;
//};
//class person
//{
//public:
//	person(string name,string phone):m_name(name),a(phone)
//	{
//		;
//	};
//	string m_name;
//	phone a;                    //在类内调用其他类
//};
// void test()
//{
//	 person p("sb", "zz");
//	 cout << "姓名：" << p.m_name << "手机是:" << p.a.m_B << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}





////初始化列表
//using namespace std;
//class person
//{
//public:
//	person(int a,int b, int c ) :m_A(a), m_B(b), m_C(c)//person (int a):m_A(a)
//	{
//		;
//	};       //初始化列表,  从 30 到 int a，再从 int a 到 m_A   ,完成赋值操作
//	int m_A;
//	int m_B;
//	int m_C;
//};
//int main()
//{
//	person p(30, 20, 10);                
//	cout << p.m_A << endl;    
//
//	return 0;
//}




////深拷贝和浅拷贝
//using namespace std;
//class person
//{
//public:
//	person(int age,int shengao)
//	{
//		m_age =age;
//		m_shengao=new int(shengao);           //开辟空间
//		cout << "有参构造调用" << endl;
//	}
//
//	 //###################################################################################################################
//	person(const person& p)//要使用深拷贝来解决问题，其要点在于重新产生一个数据而不是在调用同一个数据，从而防止重复释放
//	{
//		cout << "拷贝函数的调用" << endl;
//		m_age = p.m_age;
//		m_shengao=new int(*p.m_shengao);        //再申请一块空间，再写入
//	}
//	//####################################################################################################################
//
//	~person()                              //析构函数通常用来把堆区开辟的数据释放
//	{
//		if (m_shengao != NULL)                                                       //p2先析构了，导致p1再来析构使什么都没有而报错  ,浅拷贝导致的问题就是内存重复释放,
//		{
//			delete m_shengao;                                      
//			m_shengao = NULL;   //防止野指针的出现
//		}
//		cout << "析构函数调用" << endl;
//	}
//	int m_age;
//	int *m_shengao;          //使此时的数据开放到堆区
//};
//void test1()
//{
//	person p1(18,160);
//	cout << "年龄:" << p1.m_age << endl;
//	cout << "身高:" << *p1.m_shengao << endl;
//	person p2(p1);                           //没有写拷贝函数，此时编译器自动提供了浅拷贝的操作
//	cout << "年龄:" << p2.m_age << endl;
//	cout << "身高:" << *p1.m_shengao << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}





//构造函数的调用规则
// 创建一个类，编译器会自动弄出三个函数
//1.构造函数
//2.析构函数
//3.值拷贝函数  相当于写上了m_age=p.m_age这行代码                
// 
// 自己提供有参之后编译器不提供无参构造函数，但提供拷贝
// 自己弄了拷贝，就什么都不提供了
// 
// 一句话，三个都写上就没这么多屁事了





////拷贝函数的使用情况
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//		cout << "默认函数的调用" << endl;
//	}
//	person(int age)
//	{
//		m_age = age;
//		cout << "有参构造函数的调用" << endl;
//	}
//	person(const person& p)
//	{
//
//		m_age = p.m_age;
//		cout << "拷贝构造函数的调用" << endl;
//	}
//	~person()
//	{
//		cout << "析构函数的调用" << endl;
//	}
//	int m_age;
//};
//void test1()
//{
//	//1.使用一个已经创建的对象初始化一个新的对象
//	person p1(10);
//	person p2(p1);
//}
//void dowork(person p)   //此时进行的是值传递，值传递的本质是复制一份放入
//{
//	;
//}
//void test2()
//{
//	//2.值传递的方式给函数参数传值
//	person p;
//	dowork(p);   //拷贝到上面时是一个临时的副本，不会影响此时的数据，就是改了穿进去的值不改变原值，和加了const 差不多
//}
//person dowork2()   //虽然局部变量函数执行后就会释放，但是值传递又复制了一个值，再返回就是一个新的变量，值和原来一样
//{
//	person p1;
//	return p1;
//}
//void test3()
//{//3.值方式返回局部对象
//	person p = dowork2();//接受上面返回的     “值”
//}
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}





//构造方式
//按参数分类
//1.有参构造和无参构造
//2.普通构造和拷贝构造
//调用方法
//1.括号法
//2.显示法
//3.隐式转换法
//using namespace std;
//class Person
//{
//public:
//	
//	Person() { cout << "无参构造函数的调用" << endl; }
//	Person(int a) 
//	{ 
//		age = a;
//		cout << "有参构造函数的调用" << endl; 
//	}
//	Person(const Person& p)                //拷贝构造   //将传入的人的属性拷贝到我身上
//	{
//		age = p.age;
//		cout<< "拷贝构造函数的调用" << endl;
//	}
//	~Person() {cout <<"析构函数的调用" << endl; }
//	int age;
//};
//void test()
//{
//	// 括号法
//	Person p1;//默认构造函数的调用          不要加小括号
//	Person p2(10);//调用有参构造函数
//	Person p3(p2);//拷贝构造函数的调用
//	cout << "p2的年龄" <<p2.age << endl;
//	cout << "p3的年龄" << p3.age << endl;
//	//显示法
//	Person p1;
//	Person p2 = Person(10);   //显示的告诉编译器这是一个有参构造
//	Person p3 = Person(p2);   //显示=调用拷贝构造
//	Person(10);//单独出现叫做匿名对象  此行结束后就会立即回收该对象   //不要用拷贝构造初始化匿名对象Person(p3)==Preson p3 会被认为是对象的一个声明
//	//隐式转换法
//	Person p4 = 10;  //相当于谢了Person p4 = Perosn(10)
//	Person p5 = p4;  //拷贝构造
//}
//int main()
//{
//	test();
//}





////构造函数和析构函数
////构造函数语法    类名(){}    可以有参数，可以重载
////析构函数语法    ~类名(){}    不能有参数，不能重载
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//		cout << "person构造函数的调用" << endl;
//	}
//	~person()
//	{
//		cout << "person析构函数的调用" << endl;
//	}
//};
//void test()                                      //栈上的数据，test执行完了就会自动释放
//{
//	person p1;   //创建的时候自动调用的，只调用一次       
//}
//int main()
//{
//	test();
//	return 0;
//}





//可以在一个类中使另一个类成为一个成员
//文件操作详见长方体那里






//using namespace std;
//class C
//{
//public:
//	void set_c(int c)
//	{
//		m_c = c;
//	}
//	int get_c()
//	{
//		return m_c;
//	}
//	void set_k(int k)
//	{
//		m_k = k;
//	}
//	int get_k()
//	{
//		return m_k;
//	}
//	void set_g(int g)
//	{
//		m_g = g;
//	}
//	int get_g()
//	{
//		return m_g;
//	}
//	int mianji()
//	{
//		return 2 * m_c * m_k + 2 * m_c * m_g + 2 * m_g * m_k;
//	}
//	int tiji()
//	{
//		return m_k * m_g * m_c;
//	}
//	bool neibuxiangdeng(C &c)
//	{
//		if (m_c == c.get_c() && m_g == c.get_g() && m_k == c.get_k())
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//private:
//	int m_c;
//	int m_k;
//	int m_g;
//};
//
//bool xiangdeng(C &c1, C &c2)     //用引用的方式传递    //bool用于判断传入的参数是否相等    //全局需要传入两个参数，局部在CLASS类中只要传入外部的就行，与内部进行比较
//{
//	if (c1.get_c() == c2.get_c() && c1.get_g() == c2.get_g() && c1.get_k() == c2.get_k())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int main()
//{
//	C c1;
//	c1.set_c(10);
//	c1.set_g(10);
//	c1.set_k(10);
//	cout << c1.mianji() << endl;
//	cout << c1.tiji() << endl;
//	C c2;
//	c2.set_c(10);
//	c2.set_g(10);
//	c2.set_k(10);
//	bool ret = xiangdeng(c1, c2);
//	if (ret)
//	{
//		cout << "相等" << endl;
//	}
//	else
//	{
//		cout << "不相等" << endl;
//	}
//	ret = c1.neibuxiangdeng(c2);    //使用类内判断时只需要传入一个参数
//	{
//		if (ret)
//		{
//			cout << "内部相等" << endl;
//		}
//		else
//		{
//			cout << "不内部相等" << endl;
//		}
//	}
//	return 0;
//}






//using namespace std;
//class D
//{
//public:
//	void setname(string name)//设置姓名,外部的接口，使可以访问私有的部分
//	{
//		m_name=name;
//	}                          //以成员函数的方式访问私有部分
//	string getname()//获取姓名
//	{
//		return m_name;
//	}
//private:
//	string m_name;
//};
//int main()
//{
//	D a1;
//	a1.setname("傻逼");
//	cout << "姓名是：" << a1.getname() << endl;
//}                                                  






//类和对象     访问权限
//1.public  类内和类外都可以访问
//2.private  类内可以，类外不行     儿子不能访问的遗产
//3.protected 类内可以，类外不行    儿子可以访问的父亲的遗产
//struct 与class的唯一区别就是，class默认是私有的,struct默认是公共的






////类和对象   属性和行为
//using namespace std;     
//class S
//{
//public:
//	void  name(string name)  //通过函数对属性进行赋值操作 
//	{
//		s_name = name;
//	}
//	void display()   //行为  或者说成员方法
//	{
//		cout << s_name<<endl;
//	}
//private:
//	string s_name;    //属性  或者说成员变量
//};
//int main()
//{
//	S S1;
//	S1.name("傻逼");
//	S1.display();
//}






////函数重载的注意事项
////1.引用作为重载条件     
////2.函数重载碰到默认参数     出现了二义性，报错，只能尽量避免这种情况
//using namespace std;
//void func(int &a)
//{
//	cout << "sb";
//}
//void func(const int &a)
//{
//	cout << "zz";
//}
//int main()
//{
//	int a = 0;
//	func(a);           // const int 与int 引用属于类型不同
//	func(10);            //引用const int 的函数
//	return 0;
//}





////函数重载的满足条件
////1.同一个作用域下
////2.函数名称相同
////3.函数参数不同,或者个数，顺序不同
//using namespace std;
//void func(double a=0)
//{
//	cout << "sb" << endl;
//}
//void func(int a = 10)
//{
//	cout << "zz" << endl;
//}
////函数的返回值不可以作为函数重载的条件
//int main()
//{
//	func(10.0);   //根据传入参数的不同走不同的函数
//	return 0;
//}





//using namespace std;
//int func(int a = 10, int b = 20, int c = 30); //2.如果函数的声明已经有默认参数，函数实现就不能有默认参数,即使没红线，但还是会报错，声明和实现只能有一个默认参数
//
//int func(int a,int b=20,int c=30)     //初始化默认函数参数，1.如果某个位置默认参数，从这个参数后面都要有默认参数，比如现在a没有默认参数，但是b有，从b后面就都必须要有
//{
//	return a + b + c;
//}
//int main()
//{
//	cout << func(10, 30) << endl;    //在这里可以对已经初始化的值进行更改      
//}





//栈区中存放函数的参数和局部变量等，自动分配空间和释放,不要返回局部变量的地址
//程序运行之前有两个区域，一个代码区，一个全局区 
//代码区特点是共享和只读
// 常量区中放的是  全局常量和字符串常量
//数据的储存中  全局常量  全局变量  静态变量  字符串常量 的储存位置都非常的接近,都储存在全局区中   局部变量  用const修饰的局部变量都不在全局变量中





//引用的本质就是c++内部的一个指针常量,所以不可以更改
//引用作为返回值使用
// 不要返回局部变量的引用,使用局部变量返回时第一次编译器会保留结果，第二次就错误了，因为被释放掉了，但是使用static 控制的静态变量是全局变量，程序结束时才被释放，所以此时引用 作为返回值就可以使用
//函数调用可以作为左值,因为返回的是a（被引用数）的引用，所以作为左值时就是a的引用，所以可以直接作为左值，本质就是a，对其进行赋值
 





//传递的方式
//值传递,无法在函数中实现交换操作，形参不会修饰实参
//地址传递，形参会修饰实参
//引用传递形参也会修饰实参
//using namespace std;
//void jiaohuan(int& a, int& b)  //实质上已经使用了别名，但是并没有将原名的值赋予某一个别名，而是直接以应用的方式存在，其存在方式和直接使用别名一致
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}                     //引用传递实现交换
//int main()
//{
//	int a = 10;
//	int b = 20;
//	jiaohuan(a, b);
//	cout << a << endl;
//	cout << b << endl;
//}





////引用
//using namespace std;
//int main()
//{
//	int b = 10;  //先创建一个引用
//	int &a=b;   //  引用格式   数据类型 &别名=原名
//	int c = 20;
//	//int& c = b;//引用不可以被更改   ，即已经当了b的引用就无法当其他的引用,能代表彼此，要有对象,不能出轨
//	cout << b;
//}




////堆区的管理是由程序猿开辟和释放的，当程序结束时会自动释放    指针本身也是以个局部变量，储存在栈区，但其指向的数据保存在堆区
//////动态内存的开辟和释放
//using namespace std;
//int*pc()
//{
//	int* p = new int(10);  //创建一个内存
//	return p;
//}
//void pb()
//{
//	int* arr = new int[10];//返回一个十个元素的连续空间的首地址
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i + 100;
//	}
//	for (int j = 0; j < 10; j++)
//	{
//		cout << arr[j + 0] << endl;
//	}
//	delete[] arr;//释放数组前面要加[]
//	cout << arr;  //此时空间已经释放，显示的是未初始化这片空间
//}
//int main()
//{
//	int *p=pc();
//	cout << *p << endl;	
//	delete p;                   //通过地址删除开辟的动态内存
//	pb();
//	return 0;
//}





//using namespace std;
//class student
//{
//public:
//	student(int, char[], char, float);
//	int get_num() { return num; }
//	char* get_name() { return name; }
//	char get_sex() { return sex; }
//	void display()
//	{cout << "num:" << num << "\nname:" << name << "\nsex:" << sex << "\nscore:" << "\n\n";}
//private:
//	int num;
//	char name[20];
//	char sex;
//	float score;
//};
//student::student(int n, char nam[], char s, float so)
//{
//	num = n;
//	strcpy(name, nam);
//	sex = s;
//	score = so;
//}
//class teacher
//{
//public:
//	teacher(){}
//	teacher(student&);
//	teacher(int n, char nam[], char sex, float pay);
//	void display();
//private:
//	int num;
//	char name[20];
//	char sex;
//	float pay;
//};
//teacher::teacher(int n, char nam[], char s, float p)
//{
//	num = n;
//	strcpy(name, nam);
//	sex = s;
//	pay = p;
//}
//teacher::teacher(student& stud)
//{
//	num = stud.get_num();
//	strcpy(name, stud.get_name());
//	sex = stud.get_sex();
//	pay = 1500;
//}
//void teacher::display()
//{
//	cout << "num:" << num << "\nname:" << name << "\nsex:" << sex << "\nscore:" << "\n\n";
//}
//int main()
//{
//	teacher teacher1(10001, "li", 'f', 1234.5), teacher2;
//	student student1( 20010,"wang", 'm', 89.5);
//	cout << "student1:" << endl;
//	student1.display();
//	teacher2 = teacher(student1);
//	cout << "teacher2:" << endl;
//	teacher2.display();
//	return 0;
//}






//#include<iostream>
//using namespace std;
//class matrix
//{
//public:
//	matrix();
//	friend matrix operator+(matrix&, matrix&);
//	void input();
//	void display();
//private:
//	int mat[2][3];
//};
//matrix::matrix()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			mat[i][j] = 0;
//	}
//}
//matrix operator + (matrix & a, matrix & b)
//{
//	matrix c;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			c.mat[i][j] = a.mat[i][j]+b.mat[i][j];
//	}
//	return c;
//}
//void matrix::input()
//{
//	cout << "input value of matrix:" << endl;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> mat[i][j];
//		}
//	}
//}
//void matrix::display()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << mat[i][j] << " ";
//		}
//	}
//	cout << endl;
//}
//int main()
//{
//	matrix a, b, c;
//	a.input();
//	b.input();
//	cout << endl << " matrix a:" << endl;
//	a.display();
//	cout << endl << " matrix b:" << endl;
//	b.display();
//	c = a + b;
//	cout << endl << " matrix c=matrix a + matrix b: " << endl;
//	c.display();
//	return 0;
//}






//#include<iostream>
//using namespace std;
//class complex
//{
//public:
//	complex() { real = 0; imag = 0; }
//	complex(double r, double i) { real = r; imag = i; }
//	complex operator + (complex& c2);
//	complex operator - (complex& c2);
//	complex operator * (complex& c2);
//	complex operator / (complex& c2);
//	void display();
//private:
//	double real;
//	double imag;
//};
//complex complex::operator + (complex & c2)
//{
//	complex c;
//	c.real = real + c2.real;
//	c.imag = imag + c2.imag;
//	return c;
//}
//complex complex::operator - (complex& c2)
//{
//	complex c;
//	c.real = real - c2.real;
//	c.imag = imag - c2.imag;
//	return c;
//}
//complex complex::operator * (complex& c2)
//{
//	complex c;
//	c.real = real * c2.real-imag*c2.imag;
//	c.imag = imag * c2.real+real*c2.imag;
//	return c;
//}
//complex complex::operator / (complex& c2)
//{
//	complex c;
//	c.real = (real * c2.real + imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
//	c.imag = (imag * c2.real - real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
//	return c;
//}
//void complex::display()
//{
//	cout << "(" << real << "," << imag << "i)" << endl;
//}
//int main()
//{
//	complex c1(3, 4), c2(5, 10), c3;
//	c3 = c1 + c2;
//	cout << "c1+c2=";
//	c3.display();
//	c3 = c1 - c2;
//	cout << "c1-c2=";
//	c3.display();
//	c3 = c1 * c2;
//	cout << "c1*c2=";
//	c3.display();
//	c3 = c1 / c2;
//	cout << "c1/c2=";
//	c3.display();
//	return 0;
//}







//using namespace std;
//class Parse 
//{
//private:
//    string S;
//public:
//    Parse(string s);
//    int diyi();
//    Parse();
//};
//Parse::Parse(string s) 
//{
//    S = s;
//}
//Parse::Parse() {}        //防止重载报错
//int Parse::diyi()
//{
//    int a = S.find("-");
//    string b = S.substr(0, a);
//    int res =stoi(b);            
//    return res;
//}
//int main() 
//{
//	string s{};
//	cin >> s; 
//	Parse p(s);
//	cout << p.diyi() << ' ' << p.diyi()+1; 
//	return 0;
//}