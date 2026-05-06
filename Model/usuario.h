#pragma once
using namespace System;

//en usuario.h, definimos la clase Usuario que representa a un usuario en el sistema. Esta clase tiene atributos para almacenar el nombre de usuario, la contraseña y un token de verificación. También incluye métodos para autenticar al usuario comparando el token de verificación con el hash MD5 del nombre de usuario concatenado con la contraseña ingresada.

namespace Model {
	[Serializable]  // Atributo para indicar que esta clase puede ser serializada, lo que es útil para guardar objetos de tipo Usuario en archivos o bases de datos
	public ref class Usuario
	{
	public:
		String^ username;
		String^ password;
		String^ verificationToken;
		Usuario(); // Constructor por defecto que inicializa los atributos con valores vacíos
		void setVerificationToken(String^ token);// Método para establecer el token de verificación basado en el nombre de usuario y la contraseña, utilizando el hash MD5
		Usuario(String^ username, String^ password); // Constructor que permite inicializar el nombre de usuario y el token de verificación al crear un objeto Usuario
		bool autentificar();
	};
}