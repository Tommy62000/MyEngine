#include "Scene.h"

void Scene::addMesh(std::unique_ptr<Mesh> mesh) {
    meshes.push_back(std::move(mesh));
}

const std::vector<std::unique_ptr<Mesh>>& Scene::getMeshes() const {
    return meshes;
}

void Scene::addDirectionalLight(const DirectionalLight& light) {
    directionalLights.push_back(light);
}

const std::vector<DirectionalLight>& Scene::getDirectionalLights() const {
    return directionalLights;
}