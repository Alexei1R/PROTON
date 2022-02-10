#pragma once
#include <iostream>
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>



class Model {
private:
	std::vector<Mesh> meshes;
	std::string directory;


public:
	Model(char* path);
	void Draw(Shader shader);

private:
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);



};



