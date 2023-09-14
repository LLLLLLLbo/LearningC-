class bar
{

public:

	bar() = default;
};
void foo() {
	bar* ptr = new bar(); //实例化对象
	
	//...省略一些操作


	delete ptr; //存在问题
				//1.若省略操作的部分抛出异常导致程序无法向下执行(无法删除ptr指针)
				//2.不符合c++的惯用法,这种情况下99%的可能性都不应该使用堆来进行内存的分配,而应该使用栈来进行分配
}			

//下面的代码是常见的比较合理的,但是分配以及释放不在一个函数内

bar* make_bar() {
	
	//..省略一些操作

	try {
		bar* ptr = new bar();
		//..省略一些操作
	}
	catch (...) {
		delete ptr;
		throw;
	}
	return ptr;
}
void foo() {
	
	//...省略一些操作
	
	bar* ptr = make_bar();
	
	//...省略一些操作

	delete ptr;
}