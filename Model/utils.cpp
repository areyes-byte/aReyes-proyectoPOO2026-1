#include "pch.h"
#include "utils.h"
using namespace System;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace Model;


//En utils.cpp, implementamos la función GetMD5Hash que se declaró en utils.h. Esta función toma una cadena de entrada y devuelve su hash MD5 como una cadena hexadecimal.

String^ Utils::GetMD5Hash(String^ entrada) { //Función estática para obtener el hash MD5 de una cadena de entrada
	//Protección contra entradas nulas: si la cadena de entrada es nula, retornamos un string vacío para evitar errores al intentar procesar una cadena nula.
	if (entrada == nullptr) return String::Empty;

	
	// 1. Convertir el String^ de entrada a un arreglo de bytes
	array<Byte>^ inputBytes = Encoding::UTF8->GetBytes(entrada);
	// 2. Crear una instancia del proveedor de MD5
	MD5^ md5 = MD5::Create();
	// 3. Calcular el hash
	array<Byte>^ hashBytes = md5->ComputeHash(inputBytes);
	// 4. Crear un StringBuilder para recolectar los bytes y construir la cadena final
	// Usamos gcnew porque StringBuilder es un tipo de referencia de .NET
	StringBuilder^ sBuilder = gcnew StringBuilder();
	// 5. Formatear cada byte como string hexadecimal
	for (int i = 0; i < hashBytes->Length; i++) {
		/* "x2" es un formato de cadena:
		   - 'x' significa hexadecimal en minúsculas.
		   - '2' asegura que siempre tenga dos dígitos (ej. 0xf se convierte en "0f").
		*/
		sBuilder->Append(hashBytes[i].ToString("x2"));
	}
	// 6. Retornar el string hexadecimal completo
	return sBuilder->ToString();
};

