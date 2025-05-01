#include "app.h"

App::App() {
    CPU cpu;
}
bool App::mainMenu() {
    int cmd;
    cout << "1. Inicializar DRAM desde archivo" << endl
         << "2. Generar instrucciones aleatoriamente" << endl
         << "3. Imprimir cache" << endl
         << "4. Exportar archivos" << endl
         << "-------------------------------------------------" << endl;
    cin >> cmd;
    cout << endl;
    switch(cmd) {
        case 1:
            initializeDRAM();
            break;
        case 2:
            generateInstructions();
            break;
        case 3:
            printCache();
            break;
        case 4:
            break;
    }
}
void App::initializeDRAM() {
    string filename;
    cout << "Escriba el nombre y la extension del archivo (ej: in.txt): ";
    cin >> filename;
    cout << endl;
    cpu.loadDRAMFromFile(Constants::FILES_PATH + filename);
}
void App::generateInstructions() {
    int k;
    cout << "Escriba el numero de instrucciones aleatorias: " << endl;
    cin >> k;
    cout << endl;
    Generator::generateInstructions(cpu, k);
}
void App::printCache() {
    cpu.printCache();
    cout << endl;
}
void App::exportFiles() {
    string filename;
    cout << "Escriba el nombre y la extension del archivo (ej: out.txt): ";
    cin >> filename;
    cout << endl;
    cpu.generateDRAMFile(Constants::FILES_PATH + filename);
    FileManager::generateLogFile();
}