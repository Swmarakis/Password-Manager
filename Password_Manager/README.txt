Giorgos Somarakis
csd4797

Part_B
Password_Manager:
    1) To compile the assignment.
        Run: $ make
    2) How to use Save_Mode. 
        $ ./pm save -f <path> <website> <username> <pass>

        where <path> is the path to the password file
        where <website> the name of the webite ex. google.com
        where <username> and <password> for ex. Somarakis Pass123

        for ex. 
        $ ./pm save -f ~Desktop/vault.dat www.google.cop Somarakis Pass123

        After this the program will ask you to make the master password for the file encryption.

    3) How to use Get_Mode.
        $ ./pm get -f <path> <website>

        where <path> is the path from the existing file
        and <website> the name of the website

        !!try to give an accurate website name, 
        the slightest mistake in the name the program will not be able to work!!

        for Ex.
            $ ./pm get -f ~Desktop/vault.dat www.google.com
        next the program will ask to you to give the master password for decryption

    Thanks for reading.
    

