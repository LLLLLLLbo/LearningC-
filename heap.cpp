class bar
{

public:

	bar() = default;
};
void foo() {
	bar* ptr = new bar(); //ʵ��������
	
	//...ʡ��һЩ����


	delete ptr; //��������
				//1.��ʡ�Բ����Ĳ����׳��쳣���³����޷�����ִ��(�޷�ɾ��ptrָ��)
				//2.������c++�Ĺ��÷�,���������99%�Ŀ����Զ���Ӧ��ʹ�ö��������ڴ�ķ���,��Ӧ��ʹ��ջ�����з���
}			

//����Ĵ����ǳ����ıȽϺ����,���Ƿ����Լ��ͷŲ���һ��������

bar* make_bar() {
	
	//..ʡ��һЩ����

	try {
		bar* ptr = new bar();
		//..ʡ��һЩ����
	}
	catch (...) {
		delete ptr;
		throw;
	}
	return ptr;
}
void foo() {
	
	//...ʡ��һЩ����
	
	bar* ptr = make_bar();
	
	//...ʡ��һЩ����

	delete ptr;
}