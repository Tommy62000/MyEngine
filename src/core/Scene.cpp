#include "Scene.h"

void Scene::addMesh(std::unique_ptr<Mesh> mesh) {
    meshes.push_back(std::move(mesh));
}

const std::vector<std::unique_ptr<Mesh>>& Scene::getMeshes() const {
    return meshes;
}