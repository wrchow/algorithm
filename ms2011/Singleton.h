// for 百度面试题
// by wr-chow at 20110903

// 一个实例
// 自己创建唯一实例
// 给所有其他对象提供这一实例
Class Singleton{

public:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;	
}