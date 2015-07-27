#srm144-div2-Time-whatTime.py
class Time:
	def whatTime(self, seconds):
		s = seconds % 60
		seconds /= 60
		m = seconds % 60
		seconds /= 60
		h = seconds
		return '%d:%d:%d' % (h, m, s)
        