#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	SmartStack<float> s;

	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	s.Push(5.0);
	s.Push(1.0);

	assert(s.GetMax() == 5.0);
	assert(s.GetMin() == 1.0);

	s.Pop();
	s.Pop();

	assert(s.GetMax() == 1.0);
	assert(s.GetMin() == 1.0);

	s.Pop();
	s.Pop();
	s.Pop();

	s.Push(1.0);
	s.Push(2.0);
	s.Push(3.0);
	s.Push(3.0);
	s.Push(4.0);
	s.Push(4.0);
	s.Push(4.0);
	s.Push(5.0);

	assert(s.GetMax() == 5.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	assert(s.GetMax() == 4.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	assert(s.GetMax() == 4.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	assert(s.GetMax() == 4.0);
	assert(s.GetMin() == 1.0);

	s.Pop();


	assert(s.GetMax() == 3.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	assert(s.GetMax() == 3.0);
	assert(s.GetMin() == 1.0);


	s.Pop();

	assert(s.GetMax() == 2.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	assert(s.GetMax() == 1.0);
	assert(s.GetMin() == 1.0);

	s.Pop();

	s.Push(3.0);

	assert(s.GetMax() == 3.0);
	assert(s.GetMin() == 3.0);

	s.Pop();

	assert(s.GetMax() == std::numeric_limits<float>::lowest());
	assert(s.GetMin() == std::numeric_limits<float>::max());

	SmartStack<float> ss;

	std::cout << ss.GetMax() << ss.GetMin() << std::endl;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);

	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -5.9f);
	assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);

	SmartQueue<int>* sq = new SmartQueue<int>();

	sq->Enqueue(6);
	sq->Enqueue(5);
	sq->Enqueue(-2);

	assert(sq->Peek() == 6);
	assert(sq->GetCount() == 3);

	int i = sq->Dequeue();

	assert(i == 6);
	assert(sq->GetCount() == 2);
	assert(sq->Peek() == 5);

	sq->Enqueue(1);
	sq->Enqueue(1);
	sq->Enqueue(1);
	sq->Enqueue(1);
	sq->Enqueue(1);

	assert(sq->GetMax() == 5);
	assert(sq->GetMin() == -2);

	delete sq;

	SmartQueue<int> q;
	q.Enqueue(6);
	q.Enqueue(5);
	q.Enqueue(-2); // [ 6, 5, -2 ]

	assert(std::abs(q.GetSum() - 9.0) <= EPSILON);
	assert(std::abs(q.GetVariance() - 12.667) <= EPSILON);
	assert(std::abs(q.GetStandardDeviation() - 3.559) <= EPSILON);

	QueueStack<int> qs(3);

	std::cout << qs.GetMax() << std::endl;
	std::cout << qs.GetMin() << std::endl;

	qs.Enqueue(1); // [ [ 1 ] ]
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

	QueueStack<int> qs2(qs);
	QueueStack<int> qs3 = qs;

	assert(qs.GetSum() == 15);
	assert(qs.GetStackCount() == 2);
	assert(qs.GetMin() == 1);
	assert(qs.GetMax() == 5);
	assert(qs.Peek() == 3);
	assert(qs.GetCount() == 5);
	assert(qs.Dequeue() == 3);
	assert(qs.GetMax() == 5);
	assert(std::abs(qs.GetAverage() - 3) <= EPSILON);
	assert(qs.Dequeue() == 2);
	assert(qs.GetMin() == 1);
	assert(qs.GetMax() == 5);
	assert(qs.Dequeue() == 1);
	assert(qs.GetMin() == 4);
	assert(qs.GetMax() == 5);
	assert(qs.Dequeue() == 5);
	assert(qs.GetMax() == 4);
	assert(qs.GetMin() == 4);
	assert(qs.Dequeue() == 4);
	assert(qs.GetCount() == 0);
	assert(qs.GetSum() == 0);
	assert(qs.GetStackCount() == 0);

	assert(qs2.GetSum() == 15);
	assert(qs2.GetStackCount() == 2);
	assert(qs2.GetMin() == 1);
	assert(qs2.GetMax() == 5);
	assert(qs2.Peek() == 3);
	assert(qs2.GetCount() == 5);
	assert(qs2.Dequeue() == 3);
	assert(qs2.GetMax() == 5);
	assert(std::abs(qs2.GetAverage() - 3) <= EPSILON);
	assert(qs2.Dequeue() == 2);
	assert(qs2.GetMin() == 1);
	assert(qs2.GetMax() == 5);
	assert(qs2.Dequeue() == 1);
	assert(qs2.GetMin() == 4);
	assert(qs2.GetMax() == 5);
	assert(qs2.Dequeue() == 5);
	assert(qs2.GetMax() == 4);
	assert(qs2.GetMin() == 4);
	assert(qs2.Dequeue() == 4);
	assert(qs2.GetCount() == 0);
	assert(qs2.GetSum() == 0);
	assert(qs2.GetStackCount() == 0);

	assert(qs3.GetSum() == 15);
	assert(qs3.GetStackCount() == 2);
	assert(qs3.GetMin() == 1);
	assert(qs3.GetMax() == 5);
	assert(qs3.Peek() == 3);
	assert(qs3.GetCount() == 5);
	assert(qs3.Dequeue() == 3);
	assert(qs3.GetMax() == 5);
	assert(std::abs(qs3.GetAverage() - 3) <= EPSILON);
	assert(qs3.Dequeue() == 2);
	assert(qs3.GetMin() == 1);
	assert(qs3.GetMax() == 5);
	assert(qs3.Dequeue() == 1);
	assert(qs3.GetMin() == 4);
	assert(qs3.GetMax() == 5);
	assert(qs3.Dequeue() == 5);
	assert(qs3.GetMax() == 4);
	assert(qs3.GetMin() == 4);
	assert(qs3.Dequeue() == 4);
	assert(qs3.GetCount() == 0);
	assert(qs3.GetSum() == 0);
	assert(qs3.GetStackCount() == 0);


	SmartQueue<double> sq1;

	std::cout << sq1.GetMax() << std::endl;
	std::cout << sq1.GetMin() << std::endl;

	sq1.Enqueue(3);
	sq1.Enqueue(0);
	sq1.Enqueue(5);
	
	assert(sq1.GetMax() == 5);
	assert(sq1.GetMin() == 0);
	sq1.Dequeue();
	assert(sq1.GetMax() == 5);
	assert(sq1.GetMin() == 0);
	sq1.Dequeue();
	assert(sq1.GetMin() == 5);
	assert(sq1.GetMax() == 5);
	sq1.Dequeue();

	

	return 0;
}