#include "CryptFiles.h"
#include <string.h>
#include <QFileDialog>
#include <time.h>


// constructor for UI
CryptFiles::CryptFiles(QWidget *parent): QMainWindow(parent) {
	srand(time(NULL));// need to be executed only 1 time
	ui.setupUi(this);
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
	connect(ui.cryptButton, SIGNAL(clicked()), this, SLOT(cryptFile()));
	connect(ui.decryptButton, SIGNAL(clicked()), this, SLOT(decryptFile()));
	connect(ui.browseButton, SIGNAL(clicked()), this, SLOT(getFile()));

}

int CryptFiles::generateRandom(int max) {
	return rand() % max;
}

unsigned CryptFiles::get_file_size(const char * file_name) {
	struct stat st;
	if (stat(file_name, &st) != 0) {
		fprintf(stderr, "error when you try to see the size of the file %s : %s \n", file_name, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return st.st_size;
}


void CryptFiles::generateRandomVectors() {
	srand(time(NULL));// need to be executed only 1 time
	long int fileSize = this->get_file_size(this->pathFile);
	std::vector<int> randomVector(fileSize);
	for (int i = 0; i < randomVector.size(); i++) {
		randomVector[i] = this->generateRandom(fileSize);
	}
	std::vector<int> sortedVector(randomVector);

	// sorting random vector
	int level = 0; // reprezents the number of levels in mergesrt, graph
	mergeSort(sortedVector, fileSize, level);


	this->randomVector = randomVector;
	this->sortedVector = sortedVector;
	
}
void CryptFiles::getFile() {
	QString s1 =QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen","Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");
	QByteArray ba = s1.toLatin1();
	const char *c_str2 = ba.data();
	// get the path of the folder, when you click browse, then copy in the *pathFile parameter
	strcpy(this->pathFile, c_str2);
	//ui.lineEdit->setText(this->pathFile);
	ui.browseLabel->setText(this->pathFile);
	// now make the Decrypt and AfterDecrypt paths also
	strcpy(this->pathFile2, this->pathFile);
	strcpy(this->pathFile3, this->pathFile);

	// now concat them
	strcat(this->pathFile2, "_Crypted.txt");
	strcat(this->pathFile3, "_DeCrypted.txt");
	// verifica daca utilizatorul a selectat ceva
	//if (s1 != NULL) {
	//generateRandom();
	//}
}

void  CryptFiles::cryptFile() {
	ui.messageLabel->setText(" ");
	FILE *f1 = fopen(pathFile, "r+");
	FILE *f2 = fopen(pathFile2, "w+");
	if (f1 == NULL) {
		ui.messageLabel->setText("can't open the file, please select an existing .txt file");
		return;
	}
	generateRandomVectors();
	//ui.lineEdit_2->setText(randomVector[1]);
	std::vector<int> copyRandomVector(randomVector.size(), -2);
	std::vector<int> copySortedVector(sortedVector.size(), -1);
	int k = 0; // copySortedVector indice

	for (int i = 0; i < sortedVector.size(); i++) {
		for (int j = 0; j < randomVector.size(); j++) {
			if (sortedVector[i] == randomVector[j]) {
				fseek(f1, j, SEEK_SET);
				char c = fgetc(f1);
				char specialCases[] = { '\n', '\t' };
				if (c == specialCases[0] || c == specialCases[1]) {
					fputc(c, f2);
					copySortedVector[k] = sortedVector[i]; k++;
					copyRandomVector[j] = randomVector[j];
					randomVector[j] = -1;
					if (j != 0) {
						fseek(f1, j - 1, SEEK_SET);
						c = fgetc(f1);
						if (c == '\n') {
							randomVector[j - 1] = -1;
						}
					}
					if (j + 1 < sortedVector.size()) {
						fseek(f1, j + 1, SEEK_SET);
						c = fgetc(f1);
						if (c == '\n') {
							randomVector[j + 1] = -1;
						}
					}
				}
				else {
					fputc(c, f2);
					copyRandomVector[j] = randomVector[j];
					randomVector[j] = -1;
					copySortedVector[k] = sortedVector[i]; k++;
					break;
				}
			}
		}
	}
	sortedVector = copySortedVector;
	randomVector = copyRandomVector;
	fclose(f1);
	fclose(f2);
	ui.messageLabel->setText(" file successfully crypted");
}
void  CryptFiles::decryptFile() {

	if (sortedVector.size() == 0) return; // if there is nothing do decrypt


	FILE *f2 = fopen(pathFile2, "r+"); // criptat
	FILE *f3 = fopen(pathFile3, "w+"); // decriptat
	if (f2 == NULL) {
		printf("can't open the file");
		return;
	}

	for (int i = 0; i < randomVector.size(); i++) {
		for (int j = 0; j < sortedVector.size(); j++) {
			if (sortedVector[j] == randomVector[i]) {
				fseek(f2, 0, SEEK_SET);
				int aux = j;
				char c;
				if (aux == 0) c = fgetc(f2);
				else {
					while (aux != -1) {
						c = fgetc(f2);
						aux--;
					}
				}
				fputc(c, f3);
				sortedVector[j] = -1;
				break;
			}
		}
	}


	fclose(f2);
	fclose(f3);
}
// declaration of exit() method in CryptFiles.h
void CryptFiles::exitApp() {
	QApplication::exit();// build-in method in QT framework

}