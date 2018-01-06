#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CryptFiles.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
using namespace std;

class CryptFiles : public QMainWindow
{
	Q_OBJECT

public:
	CryptFiles(QWidget *parent = Q_NULLPTR);
	char *pathFile = (char *)malloc(1000 * sizeof(char));
	char *pathFile2 = (char *)malloc(1000 * sizeof(char));
	char *pathFile3 = (char *)malloc(1000 * sizeof(char));
	std::vector<int> sortedVector;
	std::vector<int> randomVector;

	static void merge(vector<int> &left, int nLeft, vector<int> &right, int nRight, vector<int> &A, int n) {
		int i = 0, j = 0, k = 0; // i->left[i], j->right[j], k->A[k]
		while (i < nLeft && j < nRight) {
			if (left[i] <= right[j]) {
				A[k] = left[i];
				i++;
			}
			else {
				A[k] = right[j];
				j++;
			}
			k++;
		}
		// put the remaining elements in A
		while (i < nLeft) {
			A[k] = left[i];
			i++;
			k++;
		}
		while (j < nRight) {
			A[k] = right[j];
			j++;
			k++;
		}
	}

	static void mergeSort(vector<int> &A, int n, int level) {
		if (n < 2) return;
		int mid = (n / 2);
		std::vector<int> left(mid);
		std::vector<int> right(n - mid);
		for (int i = 0; i < mid; i++) {
			left[i] = A[i];
		}
		for (int i = mid; i < n; i++) {
			right[i - mid] = A[i];
		}

		if (level < 3) {
			int lvl2 = level + 1;
			std::thread leftThread(&CryptFiles::mergeSort, std::ref(left), mid, lvl2);
			std::thread rightThread(&CryptFiles::mergeSort, std::ref(right), n - mid, lvl2);

			leftThread.join();
			rightThread.join();
		}
		else {
			mergeSort(left, mid, level);
			mergeSort(right, n - mid, level);

		}
		merge(left, mid, right, n - mid, A, n);

	}




private:
	Ui::CryptFilesClass ui;
	static unsigned  get_file_size(const char *);
	int generateRandom(int);







	private slots:

	void generateRandomVectors();
	void getFile();
	void exitApp();
	void cryptFile();
	void decryptFile();

};
