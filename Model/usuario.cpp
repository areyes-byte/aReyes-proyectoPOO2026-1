#include "pch.h"
#include "usuario.h" 
#include "utils.h"
using namespace System;
using namespace Model;

//En usuario.cpp, implementamos los métodos de la clase Usuario. El constructor por defecto inicializa los atributos con valores vacíos, mientras que el segundo constructor permite establecer el nombre de usuario y el token de verificación al crear un objeto Usuario. El método autentificar compara el token de verificación con el hash MD5 del nombre de usuario concatenado con la contraseña ingresada para determinar si la autenticación es exitosa o no.

Usuario::Usuario() { // Constructor por defecto que inicializa los atributos con valores vacíos
	this->username = "";
	this->password = "";
	this->verificationToken = "";
}


Usuario::Usuario(String^ username, String^ token) { // Constructor que permite inicializar el nombre de usuario y el token de verificación al crear un objeto Usuario. La contraseña se deja vacía inicialmente, ya que se establecerá durante el proceso de autenticación.
	this->username = username;
	this->verificationToken = token;
}

bool Usuario::autentificar(String^ password) {

	if (password == nullptr) return false;
	if (this->username == nullptr) this->username = String::Empty;
	if (this->verificationToken == nullptr) return false;

	this->password = password; // Establecer la contraseña ingresada en el objeto Usuario para que pueda ser utilizada en la comparación con el token de verificación
	if (this->verificationToken == Utils::GetMD5Hash(this->username + this->password)) { // Verificar si el token de verificación coincide con el hash MD5 del usuario concatenado con la contraseña ingresada
		return true; // Autenticación exitosa
	}
	else {
		Console::WriteLine("Autenticacion fallida para el usuario: " + this->username); // Imprimir mensaje de error en la consola si la autenticación falla
		return false; // Autenticación fallida
	}
	
}