#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define CAMERA_POSITION 20

ofstream archivo;
ofstream archivo2;

void crear_objeto();
void crear_modelo_glb();
void crear_skybox();
void crear_movimiento();

void crear_objeto() {
	int identificador;
	string textura;
	int num1Geometria;
	int num2Geometria;
	int num3Geometria;
	string material;
	double posicion_x_objeto;
	double posicion_y_objeto;
	double posicion_z_objeto;
	string salir_o_no;
	cout << "Introduce el identificador(número), esto sirve para evitar repetir variables en el código, procura no poner siempre el mismo identificador:" << endl;
	cin >> identificador;
	cout << "Introduce la URL o archivo de la textura(puede ser un enlace bs64 o uno normal), y pon el archivo o enlace con comillas:" << endl;
	cin >> textura;
	cout << "Introduce el primer número x de la geometría del objeto(ej: 10):" << endl;
	cin >> num1Geometria;
	cout << "Introduce el otro número y de la geometría del objeto(ej: 20):" << endl;
	cin >> num2Geometria;
	cout << "Introduce el último número z de la geometría del objeto(ej: 10):" << endl;
	cin >> num3Geometria;
	cout << "Introduce si quieres que dentro del objeto se repita la textura o no:(S=que se repita la textura, N=que no se repita la textura), si no introduces ninguna de esas dos respuestas(introduces otra), se va a poner que se repita la textura por dentro:" << endl;
	cin >> material;
	cout << "Introduce la coordenada x del objeto donde quieres que esté:" << endl;
	cin >> posicion_x_objeto;
	cout << "Introduce la coordenada y del objeto donde quieres que esté:" << endl;
	cin >> posicion_y_objeto;
	cout << "Por último para finalizar esta etapa, introduce la coordenada z del objeto donde quieres que esté:" << endl;
	cin >> posicion_z_objeto;
	
	archivo2 << "const textureLoader" << identificador << " = new THREE.TextureLoader();" << endl;
	archivo2 << "const objeto" << identificador << "Textura = textureLoader" << identificador << ".load(" << textura << ");";
	archivo2 << "const objeto" << identificador << "Geometry = new THREE.BoxGeometry(" << num1Geometria << ", " << num2Geometria << ", " << num3Geometria << ");"<< endl;
	if(material == "S") {
		archivo2 << "const objeto" << identificador << "Material = new THREE.MeshBasicMaterial({map: " << "objeto" << identificador << "Textura, side: THREE.DoubleSide});" << endl;
		archivo2 << "const objeto" << identificador << " = new THREE.Mesh(" << "objeto" << identificador << "Geometry, " << "objeto" << identificador << "Textura);" << endl;
		archivo2 << "objeto" << identificador << ".position.set(" << posicion_x_objeto << ", " << posicion_y_objeto << ", " << posicion_z_objeto << ");" << endl;
		archivo2 << "scene.add(objeto" << identificador << ");" << endl << endl;
		
		cout << "¿Has terminado ya con todo esto el videojuego(S=Sí, N=No), si pones que sí, se va a terminar de escribir todo lo necesario para que el juego funcione, si te arrepientes de haber dicho que sí, puedes modificarlo por tí mismo o el código que genere el programa hay que colocarlo correctamente(eso ya depende de lo que tú quieras), se va a generar la función animate para que lo sepas:" << endl;
		cin >> salir_o_no;
		
		cout << endl << endl;
		
		if(salir_o_no == "S") {
			archivo2 << "function animate() {" << endl;
			archivo2 << "    requestAnimationFrame(animate);" << endl;
			archivo2 << "    renderer.render(scene, camera);" << endl;
			archivo2 << "}" << endl << endl;
			archivo2 << "animate();" << endl;
		
			cout << "Ok, gracias por haber usado este software de videojuegos." << endl;
				
		} else {
			cout << "Ok, puedes continuar con el programa." << endl;
			
			string modo_programa;
			cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
			cin >> modo_programa;
			if(modo_programa == "crear_objeto") {
				crear_objeto();
				
			} else if(modo_programa == "crear_modelo_glb") {
				crear_modelo_glb();
				
			} else if(modo_programa == "crear_skybox") {
				crear_skybox();
				
				
			} else if(modo_programa == "crear_movimiento") {
				crear_movimiento();
				
			} else {
				cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
			}
			
		}
		
	} else if(material == "N") {
		archivo2 << "const objeto" << identificador << "Material = new THREE.MeshBasicMaterial({map: " << "objeto" << identificador << "Textura});" << endl;
		archivo2 << "const objeto" << identificador << " = new THREE.Mesh(" << "objeto" << identificador << "Geometry, " << "objeto" << identificador << "Textura);" << endl;
		archivo2 << "objeto" << identificador << ".position.set(" << posicion_x_objeto << ", " << posicion_y_objeto << ", " << posicion_z_objeto << ");" << endl;
		archivo2 << "scene.add(objeto" << identificador << ");" << endl << endl;
		
		cout << "¿Has terminado ya con todo esto el videojuego(S=Sí, N=No), si pones que sí, se va a terminar de escribir todo lo necesario para que el juego funcione, si te arrepientes de haber dicho que sí, puedes modificarlo por tí mismo o el código que genere el programa hay que colocarlo correctamente(eso ya depende de lo que tú quieras), se va a generar la función animate para que lo sepas:" << endl;
		cin >> salir_o_no;
		
		cout << endl << endl;
		
		if(salir_o_no == "S") {
			archivo2 << "function animate() {" << endl;
			archivo2 << "    requestAnimationFrame(animate);" << endl;
			archivo2 << "    renderer.render(scene, camera);" << endl;
			archivo2 << "}" << endl << endl;
			archivo2 << "animate();" << endl;
		
			cout << "Ok, gracias por haber usado este software de videojuegos." << endl;
				
		} else {
			cout << "Ok, puedes continuar con el programa." << endl;
			
			string modo_programa;
			cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
			cin >> modo_programa;
			if(modo_programa == "crear_objeto") {
				crear_objeto();
				
			} else if(modo_programa == "crear_modelo_glb") {
				crear_modelo_glb();
				
			} else if(modo_programa == "crear_skybox") {
				crear_skybox();
				
				
			} else if(modo_programa == "crear_movimiento") {
				crear_movimiento();
				
			} else {
				cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
			}
			
		}
		
		
		
	} else {
		cout << "Entrada errónea, debes introducir para el material S o N." << endl;
	}
	
}

void crear_modelo_glb() {
	int identificador;
	string ruta_al_modelo_glb;
	double posicion_x_del_modelo_glb;
	double posicion_y_del_modelo_glb;
	double posicion_z_del_modelo_glb;
	double escala_x_del_modelo_glb;
	double escala_y_del_modelo_glb;
	double escala_z_del_modelo_glb;
	string salir_o_no;
	cout << "Introduce el identificador para evitar que se repita la variable en el código, evita que sea el mismo identificador en cada una:" << endl;
	cin >> identificador;
	cout << "Introduce la ruta local del modelo glb:" << endl,
	cin >> ruta_al_modelo_glb;
	cout << "Introduce la coordenada x donde quieres que esté el modelo glb:" << endl;
	cin >> posicion_x_del_modelo_glb;
	cout << "Introduce la coordenada y donde quieres que esté el modelo glb:" << endl;
	cin >> posicion_y_del_modelo_glb;
	cout << "Introduce la coordenada z donde quieres que esté el modelo glb:" << endl;
	cin >> posicion_z_del_modelo_glb;
	cout << "Introduce la escala x del modelo glb:" << endl;
	cin >> escala_x_del_modelo_glb;
	cout << "Introduce la escala y del modelo glb:" << endl;
	cin >> escala_y_del_modelo_glb;
	cout << "Introduce la escala z del modelo glb:" << endl;
	cin >> escala_z_del_modelo_glb;
	
	archivo2 << "const loader" << identificador << " = new THREE.GLTFLoader();" << endl;
	archivo2 << "loader.load(" << endl;
	archivo2 << "    '" << ruta_al_modelo_glb << "'," << endl;
	archivo2 << "     function(gltf) {" << endl;
	archivo2 << "         scene.add(gltf.scene);" << endl;
	archivo2 << "         gltf.scene.position.set(" << posicion_x_del_modelo_glb << ", " << posicion_y_del_modelo_glb << ", " << posicion_z_del_modelo_glb << ");" << endl;
	archivo2 << "         gltf.scene.scale.set(" << escala_x_del_modelo_glb << ", " << escala_y_del_modelo_glb << ", " << escala_z_del_modelo_glb << ");" << endl;
	archivo2 << "     }" << endl;
	archivo2 << ");" << endl;
	
	cout << "¿Has terminado ya con todo esto el videojuego(S=Sí, N=No), si pones que sí, se va a terminar de escribir todo lo necesario para que el juego funcione, si te arrepientes de haber dicho que sí, puedes modificarlo por tí mismo o el código que genere el programa hay que colocarlo correctamente(eso ya depende de lo que tú quieras), se va a generar la función animate para que lo sepas:" << endl;
		cin >> salir_o_no;
		
		cout << endl << endl;
		
		if(salir_o_no == "S") {
			archivo2 << "function animate() {" << endl;
			archivo2 << "    requestAnimationFrame(animate);" << endl;
			archivo2 << "    renderer.render(scene, camera);" << endl;
			archivo2 << "}" << endl << endl;
			archivo2 << "animate();" << endl;
		
			cout << "Ok, gracias por haber usado este software de videojuegos." << endl;
			
				
		} else {
			cout << "Ok, puedes continuar con el programa." << endl;
			
			string modo_programa;
			cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
			cin >> modo_programa;
			if(modo_programa == "crear_objeto") {
				crear_objeto();
				
			} else if(modo_programa == "crear_modelo_glb") {
				crear_modelo_glb();
				
			} else if(modo_programa == "crear_skybox") {
				crear_skybox();
				
				
			} else if(modo_programa == "crear_movimiento") {
				crear_movimiento();
				
			} else {
				cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
			}
			
		}
		
	
}

void crear_skybox() {
	string textura;
	double posicion_x_skybox;
	double posicion_y_skybox;
	double posicion_z_skybox;
	string salir_o_no;
	cout << "Introduce la textura del skybox(puede ser una url, bs64 o un archivo local):" << endl;
	cin >> textura;
	cout << "Introduce la coordenada x donde quieres que esté el skybox:" << endl;
	cin >> posicion_x_skybox;
	cout << "Introduce la coordenada y donde quieres que esté el skybox:" << endl;
	cin >> posicion_y_skybox;
	archivo2 << "const textureLoaderSkybox = new THREE.TextureLoader();" << endl;
	archivo2 << "const textura_skybox = textureLoaderSkybox.load('" << textura << "');" << endl;
	archivo2 << "const skybox_geometry = new THREE.BoxGeometry(1000, 1000, 1000);" << endl;
	archivo2 << "const skybox_material = new THREE.MeshBasicMaterial({ map: textura_skybox, side: THREE.BackSide});";
	archivo2 << "const skybox = new THREE.Mesh(skybox_geometry, skybox_material);" << endl;
	archivo2 << "skybox.position.set(" << posicion_x_skybox << ", " << posicion_y_skybox << ", " << posicion_z_skybox << ");" << endl;
	
	cout << "¿Has terminado ya con todo esto el videojuego(S=Sí, N=No), si pones que sí, se va a terminar de escribir todo lo necesario para que el juego funcione, si te arrepientes de haber dicho que sí, puedes modificarlo por tí mismo o el código que genere el programa hay que colocarlo correctamente(eso ya depende de lo que tú quieras), se va a generar la función animate para que lo sepas:" << endl;
		cin >> salir_o_no;
		
		cout << endl << endl;
		
		if(salir_o_no == "S") {
			archivo2 << "function animate() {" << endl;
			archivo2 << "    requestAnimationFrame(animate);" << endl;
			archivo2 << "    renderer.render(scene, camera);" << endl;
			archivo2 << "}" << endl << endl;
			archivo2 << "animate();" << endl;
		
			cout << "Ok, gracias por haber usado este software de videojuegos." << endl;
			
				
		} else {
			cout << "Ok, puedes continuar con el programa." << endl;
			
			string modo_programa;
			cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
			cin >> modo_programa;
			if(modo_programa == "crear_objeto") {
				crear_objeto();
				
			} else if(modo_programa == "crear_modelo_glb") {
				crear_modelo_glb();
				
			} else if(modo_programa == "crear_skybox") {
				crear_skybox();
				
				
			} else if(modo_programa == "crear_movimiento") {
				crear_movimiento();
				
			} else {
				cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
			}
			
		}
}

void crear_movimiento() {
	string salir_o_no;
	cout << "EL MOVIMIENTO QUE SE VA A GENERAR ES UN MOVIMIENTO QUE HACE QUE SE MUEVA LA CÁMARA, SI QUIERES QUE SE MUEVA UN OBJETO O UN MODELO GLB, TIENES QUE IMPLEMENTARLO TÚ MISMO SIGUIENDO LA LÓGICA DEL MOVIMIENTO DE LA CÁMARA." << endl;
	archivo2 << "window.addEventListener('keydown', (evento) => {" << endl;
	archivo2 << "    if(evento.code == 'ArrowRight') {" << endl;
	archivo2 << "        camera.position.x += 2;" << endl;
	archivo2 << "    }" << endl;
	archivo2 << "    if(evento.code == 'ArrowLeft') {" << endl;
	archivo2 << "        camera.position.x -= 2;" << endl;
	archivo2 << "    }" << endl;
	archivo2 << "});" << endl;
	
		cout << "¿Has terminado ya con todo esto el videojuego(S=Sí, N=No), si pones que sí, se va a terminar de escribir todo lo necesario para que el juego funcione, si te arrepientes de haber dicho que sí, puedes modificarlo por tí mismo o el código que genere el programa hay que colocarlo correctamente(eso ya depende de lo que tú quieras), se va a generar la función animate para que lo sepas:" << endl;
		cin >> salir_o_no;
		
		cout << endl << endl;
		
		if(salir_o_no == "S") {
			archivo2 << "function animate() {" << endl;
			archivo2 << "    requestAnimationFrame(animate);" << endl;
			archivo2 << "    renderer.render(scene, camera);" << endl;
			archivo2 << "}" << endl << endl;
			archivo2 << "animate();" << endl;
		
			cout << "Ok, gracias por haber usado este software de videojuegos." << endl;
			
				
		} else {
			cout << "Ok, puedes continuar con el programa." << endl;
			
			string modo_programa;
			cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
			cin >> modo_programa;
			if(modo_programa == "crear_objeto") {
				crear_objeto();
				
			} else if(modo_programa == "crear_modelo_glb") {
				crear_modelo_glb();
				
			} else if(modo_programa == "crear_skybox") {
				crear_skybox();
				
				
			} else if(modo_programa == "crear_movimiento") {
				crear_movimiento();
				
			} else {
				cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
			}
			
		}
	}

int main() {
	cout << "Bienvenido a HuguiniGameCreator, aquí vas a poder desarrollar videojuegos 3d sin tener que escribir ninguna línea de código(aunque lo podrás modificar después a tu gusto)." << endl << endl;
	string confirmacion;
	cout << "Se va a crear dos archivos index.html y un script.js, por favor, revisa que estés en el directorio de tu proyecto, si no lo estás introduce N y ejecuta este programa en el directorio de tu proyecto. Si dices S, se van a crear esos dos archivos (S=Sí, N=No):" << endl;
	cin >> confirmacion;
	if(confirmacion == "S") {
		archivo.open("index.html");
		archivo2.open("script.js");
		
		archivo << "<html>" << endl;
		archivo << "<body>" << endl;
		archivo << "<script src='cdnjs.cloudflare.com/ajax/libs/three.js/r128/three.min.js'></script>" << endl;
		archivo << "<script src='cdn.jsdelivr.net/npm/three@0.128.0/examples/js/loaders/GLTFLoader.js'></script>" << endl;
		archivo << "<script src='script.js'></script>" << endl;
		archivo << "</body>" << endl;
		archivo << "</html>";
		
		archivo.close();
		
		archivo2 << "const scene = new THREE.Scene();" << endl;
		archivo2 << "const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.01, 1000);" << endl;
		archivo2 << endl << endl;
		archivo2 << "const renderer = new THREE.WebGLRenderer();" << endl;
		archivo2 << "renderer.setSize(window.innerWidth, window.innerHeight);" << endl;
		archivo2 << "document.body.appendChild(renderer.domElement);" << endl << endl;
		archivo2 << "camera.position.z = " << CAMERA_POSITION << ";" << endl << endl;
		
		cout << "ALERTA: EL CONTENIDO DEL ARCHIVO HA SIDO ESCRITO CORRECTAMENTE, PERO TODAVÍA FALTA COSAS POR ESCRIBIR, ENTONCES, CUANDO TERMINES DE NAVEGAR ENTRE LAS FUNCIONES DE CREAR, DI SI TERMINASTES O NO, PARA QUE SI NO TERMINASTES, CONTINÚES, DE LO CONTRARIO, SE TERMINARÁ DE ESCRIBIR EL ARCHIVO JS CORRECTAMENTE." << endl;
		cout << "ADEMÁS, SI VUELVES A INICIAR EL PROGRAMA Y ANTERIORMENTE DIJISTE QUE TERMINASTE, LA FUNCIÓN ANIMATE QUE FALTA DE ESCRIBIR, SE REPETIRÁ DOS VECES, TEN CUIDADO." << endl;
				
		string modo_programa;
		cout << "Introduce el modo(crear_objeto, crear_modelo_glb, crear_skybox, crear_movimiento):" << endl;
		cin >> modo_programa;
		if(modo_programa == "crear_objeto") {
			crear_objeto();
			
		} else if(modo_programa == "crear_modelo_glb") {
			crear_modelo_glb();
			
		} else if(modo_programa == "crear_skybox") {
			crear_skybox();
			
			
		} else if(modo_programa == "crear_movimiento") {
			crear_movimiento();
			
		} else {
			cerr << "Entrada errónea, debes introducir crear_objeto, crear_modelo_glb, crear_skybox o crear_movimiento." << endl;
		}
		
		
	} else if(confirmacion == "N") {
		cout << "Ok, vuelve pronto." << endl;
		
		
	} else {
		cerr << "Entrada errónea" << endl;
		
	}
}
