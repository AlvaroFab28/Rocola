#include "RocolaManager.cpp"
DataManager* DataManager::instancia = nullptr;

int main() {
	RocolaManager::iniciar();
	exit(0);
}