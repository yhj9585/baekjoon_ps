#include <stdio.h>

int main() {
	int high, mid, low, coke, cider;
	scanf("%d %d %d %d %d", &high, &mid, &low, &coke, &cider);

	int h_coke = high + coke;
	int h_cider = high + cider;
	int m_coke = mid + coke;
	int m_cider = mid + cider;
	int l_coke = low + coke;
	int l_cider = low + cider;

	int h_l, m_l, l_l;

	if (h_coke <= h_cider) {
		h_l = h_coke;
	}
	else {
		h_l = h_cider;
	}
	if (m_coke <= m_cider) {
		m_l = m_coke;
	}
	else {
		m_l = m_cider;
	}
	if (l_coke < l_cider) {
		l_l = l_coke;
	}
	else {
		l_l = l_cider;
	}

	if (h_l <= m_l) {
		if (h_l <= l_l) {
			printf("%d", h_l - 50);
		}
		else {
			printf("%d", l_l - 50);
		}
	}
	else {
		if (m_l <= l_l) {
			printf("%d", m_l - 50);
		}
		else {
			printf("%d", l_l - 50);
		}
	}
}