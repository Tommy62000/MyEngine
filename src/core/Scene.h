#pragma once

#include <vector>
#include <memory>
#include "Mesh.h"

class Scene {
public:
    void addMesh(std::unique_ptr<Mesh> mesh);

    const std::vector<std::unique_ptr<Mesh>>& getMeshes() const;

private:
    std::vector<std::unique_ptr<Mesh>> meshes;
};