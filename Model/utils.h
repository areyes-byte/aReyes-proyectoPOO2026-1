#pragma once
//clase de utilidades como el MD5 para la autenticación de usuarios

using namespace System;


namespace Model {
	public ref class Utils
	{
	public:
		static String^ GetMD5Hash(String^ entrada); //Declaración de la función estática para obtener el hash MD5 de una cadena de entrada
	};
}  