#pragma once


namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic; // Agregar esta línea para usar Dictionary
	using namespace Model; // Agregar esta línea para usar la clase Usuario y Utils


	//Estas lineas ya no las agregamos aquí, sino que las movimos a utils.h y utils.cpp para mantener el código más organizado y modularizado. Ahora podemos usar la función GetMD5Hash desde la clase Utils en nuestro formulario sin tener que definirla directamente aquí.
	// Agregar estas líneas para usar MD5 y obtener el hash de los inputs
	//============================================================================================================
	/*using namespace System;
	using namespace System::Security::Cryptography;
	using namespace System::Text;

	String^ GetMD5Hash(String^ entrada) {
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
			// "x2" es un formato de cadena:
			  // - 'x' significa hexadecimal en minúsculas.
			  // - '2' asegura que siempre tenga dos dígitos (ej. 0xf se convierte en "0f").
			
			sBuilder->Append(hashBytes[i].ToString("x2"));
		}

		// 6. Retornar el string hexadecimal completo
		return sBuilder->ToString();
	}*/

	//============================================================================================================



	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxUser;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxPassword;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxUser = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(234, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"User";
			// 
			// textBoxUser
			// 
			this->textBoxUser->Location = System::Drawing::Point(59, 43);
			this->textBoxUser->Name = L"textBoxUser";
			this->textBoxUser->Size = System::Drawing::Size(100, 20);
			this->textBoxUser->TabIndex = 2;
			this->textBoxUser->TextChanged += gcnew System::EventHandler(this, &Login::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			this->label2->Click += gcnew System::EventHandler(this, &Login::label2_Click);
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(69, 104);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(100, 20);
			this->textBoxPassword->TabIndex = 4;
			this->textBoxPassword->UseSystemPasswordChar = true;
			this->textBoxPassword->TextChanged += gcnew System::EventHandler(this, &Login::textBoxPassword_TextChanged);
			// 
			// MyForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 192);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxUser);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Evento del botón de login al presionarlo

		// Evitar shadowing de nombres: usar nombres distintos para el String^ y para el objeto Usuario
		String^ username = this->textBoxUser->Text; // Obtener el texto ingresado en el TextBox de usuario
		String^ password = this->textBoxPassword->Text; // Obtener el texto ingresado en el TextBox de contraseña

		// Creamos un objeto Usuario para autentificarlo usando el método autentificar que compara el token de verificación con el hash MD5 del usuario concatenado con la contraseña ingresada
		Usuario^ usuario = gcnew Usuario(username, password);
		// Seteamos el token de verificación: "e447e9b4e2246ad58b5e1a91d69f3222" que es el hash MD5 de "Alonso" + "udj24c"
		
		usuario->setVerificationToken("e447e9b4e2246ad58b5e1a91d69f3222");

		if (usuario->autentificar()) { // Comparar el hash obtenido con el hash esperado
			this->Hide(); // Ocultar el formulario actual si autenticación es exitosa
			Console::WriteLine("Autenticación exitosa, bienvenido " + username);
		}
		else {
			Console::WriteLine("Autenticación fallida, usuario o contraseña incorrectos");
		}

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBoxPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
