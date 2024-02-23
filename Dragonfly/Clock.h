#ifndef CLOCK_H
#define CLOCK_H

namespace df {
	class Clock {
	private:
		long int m_prev_time; // Previous time -> delta() -> called in microseconds

	public:
		Clock(); // Set previous time to current time
		long int delta(); // Returns elapsed time since delta was last called; resets prev_time; returns in microseconds
		long int split() const; // Returns elapsed time since delta was last called; DOES NOT reset prev_time; returns in microseconds
	};
}
#endif