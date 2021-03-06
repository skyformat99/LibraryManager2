/*
Copyright� Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "MenuLists.h"
#include "Student.h"
#include "Book.h"
#include "CoreFunction.h"
#include "Card.h"
#include "Statistics.h"
Book bookList[maxBook]; // solve external struct
Student studentList[maxStudent]; // same as line 4
/*Starting Introduction function
Type : void
Input : none
Output: About author
*/
void Introduction() {
	system("cls");
	printf("\n\n\n");
	printf("\t  =================================================================================================\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                                   DAI HOC QUOC GIA TPHCM                                    ||\n");
	printf("\t  ||                              TRUONG DAI HOC KHOA HOC TU NHIEN                               ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                                  DO AN NHAP MON LAP TRINH 02                                ||\n");
	printf("\t  ||                                 CHUONG TRINH QUAN LY THU VIEN                               ||\n");
	printf("\t  ||                            Sinh Vien  : Hoang Minh Hieu                                     ||\n");
	printf("\t  ||                            Lop        : 17CK1_CL - Khoa CNTT                                ||\n");
	printf("\t  ||                            MSSV       : 1760311                                             ||\n");
	printf("\t  ||                            Dien Thoai : 0125 428 0401                                       ||\n");
	printf("\t  ||                            Email      : 1760311@student.hcmus.edu.vn                        ||\n");
	printf("\t  ||   Source code available now on my GitHub: https://github.com/hyperion0201/LibraryManager2   ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  =================================================================================================\n");
	_getch();
}
/*Starting InitializingComponents function
Type: void
Input : none
Output : waiting system and prompting user for avoiding interrupts
*/
void InitializingComponents() {
	int studentflag, bookflag, cardflag;
	printf("\n");
	printf("\t\t================= CHAO MUNG BAN DEN VOI QUAN LI THU VIEN =================\n");
	printf("\n");
	Sleep(2000);
	printf("\t Chuong trinh dang chuan bi du lieu. Vui long doi trong giay lat ");
	TimingBreak();
	if (fileChecking("./AppData/Student.txt") == 1)
	{
		Sleep(500);
		printf("\t -> Phat hien du lieu hoc sinh.\n");
		Sleep(500);
		printf("\t -> Dang doc du lieu hoc sinh");
		TimingBreak();
		FILE* studentdata = fopen("./AppData/Student.txt", "rt");
		StudentFetching(studentdata, studentList, studentcounter);
		fclose(studentdata);
		studentflag = 1;
	}
	else studentflag = 0;
	if (fileChecking("./AppData/Book.txt") == 1){
		Sleep(500);
		printf("\t -> Phat hien du lieu sach.\n");
		Sleep(500);
		printf("\t -> Dang doc du lieu sach");
		TimingBreak();
		FILE* bookdata = fopen("./AppData/Book.txt", "rt");
		BookFetching(bookdata, bookList, bookcounter);
		fclose(bookdata);
		bookflag = 1;
	}
	else bookflag = 0;
	if (fileChecking("./AppData/Card.txt") == 1){
		Sleep(500);
		printf("\t -> Phat hien du lieu the muon.\n");
		Sleep(500);
		printf("\t -> Dang doc du lieu the muon");
		TimingBreak();
		FILE* carddata = fopen("./AppData/Card.txt", "rt");
		CardFetching(carddata, cardList, brcard);
		fclose(carddata);
		cardflag = 1;
	}
	else cardflag = 0;

	if (fileChecking("./AppData/Stat.txt") == 1)
	{
		FILE* statdata = fopen("./AppData/Stat.txt", "rt");
		StatFetching(statdata);
		fclose(statdata);
	}
	if (studentflag == 0)
	{
		printf("\t -> He thong phat hien day la lan dau su dung.\n");
		Sleep(500);
		printf("\t -> Vui long khoi tao thong tin cua hoc sinh dau tien.\n\n");
		StudentDeclaration(studentList);
	}
	if (bookflag == 0)
	{
		Sleep(500);
		printf("\n\t -> Vui long khoi tao thong tin cuon sach dau tien. \n\n");
		Sleep(500);
		BookDeclaration(bookList);
	}

}
/*Starting MainMenu function
Type: integer
Input : none
Output : user's choice
*/
int MainMenu() {
	system("cls");
	int choice;
	printf("\n");
	printf("\t              CHUONG TRINH QUAN LY THU VIEN  -- HOANG MINH HIEU -- 17CK1_CL         \n");
	printf("\t      ==============================================================================\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ||                         1. Quan Ly Doc Gia                               ||\n");
	printf("\t      ||                         2. Quan Ly Sach                                  ||\n");
	printf("\t      ||                         3. Quan Li Phieu Muon,Tra Sach                   ||\n");
	printf("\t      ||                         4. Cac Thong Ke Co Ban                           ||\n");
	printf("\t      ||                         5. Xem Thong Tin Tac Gia                         ||\n");
	printf("\t      ||                         0. Thoat ung dung                                ||\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ==============================================================================\n");
	printf("                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung  :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting StudentManagementMenu function
Type: int
Input: none
Output: user's choice
*/
int StudentManagementMenu() {
	system("cls");
	int choice;
	printf("\t\t ======================= QUAN LI DOC GIA =========================\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t ||                Vui long chon cac chuc nang !                ||\n");
	printf("\t\t ||                1. Xem Doc Gia Trong Thu Vien                ||\n");
	printf("\t\t ||                2. Them Doc Gia                              ||\n");
	printf("\t\t ||                3. Chinh Sua Thong Tin Mot Doc Gia           ||\n");
	printf("\t\t ||                4. Xoa Thong Tin Mot Doc Gia                 ||\n");
	printf("\t\t ||                5. Tim Kiem Doc Gia Theo CMND                ||\n");
	printf("\t\t ||                6. Tim Kiem Sach Theo Ho Ten                 ||\n");
	printf("\t\t ||                0. Quay lai menu chinh                       ||\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t =================================================================\n");
	printf("                      Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting BookManagementMenu function
Type : int
Input: none
Output : user's choice
*/
int BookManagementMenu() {
	system("cls");
	int choice;
	printf("\t\t ========================== QUAN LI SACH ==========================\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ||             Vui long chon cac chuc nang !                    ||\n");
	printf("\t\t ||             1. Xem Danh Sach Cac Sach Co Trong Thu Vien      ||\n");
	printf("\t\t ||             2. Them Sach                                     ||\n");
	printf("\t\t ||             3. Chinh Sua Thong Tin Mot Quyen Sach            ||\n");
	printf("\t\t ||             4. Xoa Thong Tin Sach                            ||\n");
	printf("\t\t ||             5. Tim Kiem Sach Theo ISBN                       ||\n");
	printf("\t\t ||             6. Tim Kiem Sach Theo Ten Sach                   ||\n");
	printf("\t\t ||             0. Quay lai menu chinh                           ||\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ==================================================================\n");
	printf("                       Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting Statistics function
Type : int
Input: none
Output :user's input
*/
int StatisticsMenu() {
	system("cls");
	int choice;
	printf("\t\t ========================= THONG KE CO BAN =========================\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ||            Vui long chon cac chuc nang !                      ||\n");
	printf("\t\t ||            1. Thong Ke So Luong Sach Trong Thu Vien           ||\n");
	printf("\t\t ||            2. Thong Ke So Luong Sach Theo The Loai            ||\n");
	printf("\t\t ||            3. Thong Ke So Luong Doc Gia                       ||\n");
	printf("\t\t ||            4. Thong Ke So Luong Doc Gia Theo Gioi Tinh        ||\n");
	printf("\t\t ||            5. Thong Ke So Sach Dang Duoc Muon                 ||\n");
	printf("\t\t ||            6. Thong Ke Danh Sach Doc Gia Bi Tre Han           ||\n");
	printf("\t\t ||            0. Quay lai menu chinh                             ||\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ===================================================================\n");
	printf("                   Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
void IntroductionENG() {
	system("cls");
	printf("\n\n\n");
	printf("\t  =================================================================================================\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                         VIETNAM NATIONAL UNIVERSITY HO CHI MINH CITY                        ||\n");
	printf("\t  ||                                 UNIVERSITY OF SCIENCES                                      ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                               PROGRAMMING PROJECT 02                                        ||\n");
	printf("\t  ||                          THE LIBRARY MANAGER APPLICATION                                    ||\n");
	printf("\t  ||                    Student  : Hoang Minh Hieu                                               ||\n");
	printf("\t  ||                    Class        : 17CK1_CL - Faculty of Information Technology              ||\n");
	printf("\t  ||                    Student ID       : 1760311                                               ||\n");
	printf("\t  ||                    Phone : 0125 428 0401                                                    ||\n");
	printf("\t  ||                    Email      : 1760311@student.hcmus.edu.vn                                ||\n");
	printf("\t  ||    Source code available now on my GitHub: https://github.com/hyperion0201/LibraryManager2  ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  =================================================================================================\n");
	_getch();
}
int MainMenuENG() {
	system("cls");
	int choice;
	printf("\n");
	printf("\t                THE LIBRARY MANAGER SOFTWARE -- HOANG MINH HIEU -- 17CK1_CL         \n");
	printf("\t      ==============================================================================\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ||                         1. Student Management                            ||\n");
	printf("\t      ||                         2. Book Management                               ||\n");
	printf("\t      ||                         3. Library card management(borrow, return)       ||\n");
	printf("\t      ||                         4. Statistics                                    ||\n");
	printf("\t      ||                         5. See author                                    ||\n");
	printf("\t      ||                         0. Exit                                          ||\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ==============================================================================\n");
	printf("                   Please input your choice  :  ");
	scanf_s("%d", &choice);
	return choice;
}
int StudentManagementMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ======================= STUDENTS MANAGEMENT =====================\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t ||             1. See the students list in library database    ||\n");
	printf("\t\t ||             2. Create a new student                         ||\n");
	printf("\t\t ||             3. Edit a student                               ||\n");
	printf("\t\t ||             4. Delete a student                             ||\n");
	printf("\t\t ||             5. Search a student by ID                       ||\n");
	printf("\t\t ||             6. Search a student by name                     ||\n");
	printf("\t\t ||             0. Go back to menu                              ||\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t =================================================================\n");
	printf("                     Please input your choice :  ");
	scanf_s("%d", &choice);
	return choice;
}
int BookManagementMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ========================== BOOKS MANAGEMENT ==========================\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ||             1. See the books list in library's database      ||\n");
	printf("\t\t ||             2. Create a new book                             ||\n");
	printf("\t\t ||             3. Edit a book                                   ||\n");
	printf("\t\t ||             4. Delete a book                                 ||\n");
	printf("\t\t ||             5. Search a book by ISBN                         ||\n");
	printf("\t\t ||             6. Search a book by name                         ||\n");
	printf("\t\t ||             0. Go back to menu                               ||\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ==================================================================\n");
	printf("                       Please input your choice :  ");
	scanf_s("%d", &choice);
	return choice;
}
int StatisticsMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ========================= STATISTICS ==== =========================\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ||            1. Stats total books in library                    ||\n");
	printf("\t\t ||            2. Stats book by genres                            ||\n");
	printf("\t\t ||            3. Stats total students in library                 ||\n");
	printf("\t\t ||            4. Stats student by sex                            ||\n");
	printf("\t\t ||            5. Stats books which are in-use                    ||\n");
	printf("\t\t ||            6. Stats students who are in-late                  ||\n");
	printf("\t\t ||            0. Go back to menu                                 ||\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ===================================================================\n");
	printf("                  Please input your choice  :  ");
	scanf_s("%d", &choice);
	return choice;
}
void InitializingComponentsENG() {
	int studentflag, bookflag, cardflag;
	printf("\n");
	printf("\t\t================= WELCOME TO HCMUS LIBRARY MANAGER SOFTWARE =================\n");
	printf("\n");
	Sleep(2000);
	printf("\t Initiating components, please wait");
	TimingBreak();
	if (fileChecking("./AppData/Student.txt") == 1)
	{
		Sleep(500);
		printf("\t -> Students data detected.\n");
		Sleep(500);
		printf("\t -> Fetching students data");
		TimingBreak();
		FILE* studentdata = fopen("./AppData/Student.txt", "rt");
		StudentFetching(studentdata, studentList, studentcounter);
		fclose(studentdata);
		studentflag = 1;
	}
	else studentflag = 0;
	if (fileChecking("./AppData/Book.txt") == 1){
		Sleep(500);
		printf("\t -> Books data detected.\n");
		Sleep(500);
		printf("\t -> Fetching books data");
		TimingBreak();
		FILE* bookdata = fopen("./AppData/Book.txt", "rt");
		BookFetching(bookdata, bookList, bookcounter);
		fclose(bookdata);
		bookflag = 1;
	}
	else bookflag = 0;
	if (fileChecking("./AppData/Card.txt") == 1){
		Sleep(500);
		printf("\t -> Cards data detected.\n");
		Sleep(500);
		printf("\t -> Fetching cards data");
		TimingBreak();
		FILE* carddata = fopen("./AppData/Card.txt", "rt");
		CardFetching(carddata, cardList, brcard);
		fclose(carddata);
		cardflag = 1;
	}
	else cardflag = 0;

	if (fileChecking("./AppData/Stat.txt") == 1)
	{
		FILE* statdata = fopen("./AppData/Stat.txt", "rt");
		StatFetching(statdata);
		fclose(statdata);
	}
	if (studentflag == 0)
	{
		printf("\t -> Detected this is the 1st time using this app.\n");
		Sleep(500);
		printf("\t -> Please declare a student.\n\n");
		StudentDeclarationENG(studentList);
	}
	if (bookflag == 0)
	{
		Sleep(500);
		printf("\n\t -> Please declare a book. \n\n");
		Sleep(500);
		BookDeclarationENG(bookList);
	}

}
int LanguageSelection(){
	int lang;

	while (true)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t\tMoi chon ngon ngu/Select your language :\n\n");
		printf("\t\t\t\t\t\t  1. Tieng Viet \n");
		printf("\t\t\t\t\t\t  2. English  \n\n");
		printf("\n\t\t\t\t   -> Nhap vao lua chon cua ban /Input your choice : ");
		scanf_s("%d", &lang);
		if (lang == 1 || lang == 2) break;
		else
		{
			printf("\n\t\t\t  -> Lua chon khong ton tai ! / Invalid option !\n");
			Sleep(1000);
			continue;
		}
	}
	return lang;
}