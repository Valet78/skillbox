


/*
// Запись данных в файл
void saveStaffer(staffer &inWorker) {
    int lenName = inWorker.nameStaff.length();
//    int lenDate = inWorker.dateTxt.length();

    std::ofstream file(fileName, std::ios::out);
    file.write((char *) &lenName, sizeof(lenName));
    file.write((char *) &inWorker.nameStaff, lenName);
    file.write((char *) &inWorker.dateTxt, 10);
    file.write((char *) &inWorker.payments, sizeof(inWorker.payments));

    file.close();
}
 */