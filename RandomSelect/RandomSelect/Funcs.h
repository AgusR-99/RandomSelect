#pragma once
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

int generarVictima(int primerValor, int ultimoValor) {
	return rand() % (ultimoValor + 1) + primerValor;
}

bool metodoViejo(std::vector<bool*> ptr, int victima) {
	if (*ptr[victima] == false) {
		*ptr[victima] = true;
		return true;
	}
}

void metodoNuevo(std::vector<bool*> ptr, int victima) {
	*ptr[victima] = true;
	*ptr.erase(ptr.begin() + victima);
}

void resetearSerie(std::vector<bool*> ptr) {
	for (int i = 0; i < ptr.size(); i++) {
		*ptr[i] = 0;
	}
}

void mostrarSerie(std::vector<bool*> ptr) {
	std::cout << "[";
	for (int i = 0; i < ptr.size(); i++) {
		std::cout << *ptr[i] << "-";
	}
	std::cout << "]";
}

void mostrarSerie(bool *arr, int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << "-";
	}
	std::cout << "]";
}