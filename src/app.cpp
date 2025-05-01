#include "app.h"

App::App() : cpu() {}
bool App::mainMenu() {
    bool f = false;
    int cmd;
    cout << endl
         << "-------------------------------------------------" << endl
         << "1. Inicializar DRAM desde archivo" << endl
         << "2. Generar instrucciones aleatoriamente" << endl
         << "3. Imprimir cache" << endl
         << "4. Exportar archivos" << endl
         << "5. Salir" << endl
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
            exportFiles();
            break;
        case 5:
            f = true;
            break;
    }
    return f;
}
void App::initializeDRAM() {
    string filename;
    cout << "Por favor, coloque el archivo de entrada dentro de la carpeta 'files' del proyecto." << endl
         << "Luego, escriba el nombre y la extension del archivo (por ejemplo: example.txt): ";
    cin >> filename;
    cout << endl;
    cpu.loadDRAMFromFile(Constants::FILES_PATH + filename);
}
void App::generateInstructions() {
    unsigned int k;
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
    cpu.generateDRAMFile();
    FileManager::generateLogFile();
}