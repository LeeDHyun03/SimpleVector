#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <algorithm>

template <class T>
class SimpleVector
{
private:
	T* simpleVector;
	int length = 1;
public:
	SimpleVector(int length) //생성자
	{
		simpleVector = new T[length];
		for (int i = 0; i < length; i++)
		{
			simpleVector[i] = T();
		}
		this->length = length;
	}
	T GetVectorIndex(int arrayNum) const //배열[arrayNum]을 출력
	{
		return simpleVector[arrayNum];
	}
	void SetVectorIndex(int indexNum, T num) //배열[indexNum]을 num값으로 변경
	{
		if (indexNum >= 0 && indexNum < length)
		{
			simpleVector[indexNum] = num;
		}
		else
		{
			std::cerr << "Index out of range." << std::endl;
		}
	}
	int capacity() const // 배열의 길이를 반환
	{
		return length;
	}
	void Push_Back(T index)// 배열의 길이가 부족할 경우 현재 길이의 +5를 한 후 배열 넣기
	{
		bool needResize = true;
		for (int i = 0; i < length; i++)
		{
			if (!simpleVector[i])
			{
				simpleVector[i] = index;
				needResize = false;
				break;
			}
		}

		if (!needResize) return;
		//배열 길이 부족 시 진행
		resize(length + 5);

		simpleVector[length - 5] = index; //push_back
	}
	void resize(int length)
	{
		if (length < this->length) return;
		T* newSimpleVector = new T[length]; //복사용으로 사용할 임시 배열 작성

		for (int i = 0; i < length; i++)
		{
			newSimpleVector[i] = simpleVector[i]; //복사용 배열에 기존 값을 대입
		}

		for (int i = this->length; i < length; i++)
		{
			newSimpleVector[i] = T(); //복사용 배열의 값 중 기존 값이 대입되지 않은 값은 T()로 초기화
		}

		delete[] simpleVector; //이전 배열은 delete로 메모리 해제

		simpleVector = newSimpleVector; //simpleVector의 값에 복사용 배열값을 대입
		this->length = length; // length를 newLength로 변경
	}
	void Pop_Back()
	{
		for (int i = 0; i < length; i++)
		{
			if (!simpleVector[i])
			{
				simpleVector[i - 1] = NULL;
				break;
			}
		}
	}
	int size()
	{
		for (int i = 0; i < length; i++)
		{
			if (!simpleVector[i])
			{
				return i;
			}
		}
	}
	void sortData()
	{
		std::sort(simpleVector, simpleVector + size());
	}
	~SimpleVector()
	{
		//배열의 값 하나하나가 포인터타입일 경우 내부의 값을 전부 delete 해줘야함.
		delete[] simpleVector;
		std::cout << "메모리 해제" << std::endl;
	}
};
#endif
