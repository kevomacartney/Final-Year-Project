//
// Created by Kelvin Macartney on 10/02/2020.
//

#ifndef MIIND_RENDERMODEL_H
#define MIIND_RENDERMODEL_H
#include <utility>

#include "../Shaders/shaderUtil.h"
#include "../GlObjs/voaModel.h"

namespace Utilities::Rendering {
    class RenderModel {
    public:
        RenderModel(std::shared_ptr<Utilities::Shaders::ShaderUtil> shaderUtil,
                    std::shared_ptr<Utilities::GlObjs::VoaModel> voaModel)
                : ShaderUtil{std::move(shaderUtil)},
                  VoaModel{std::move(voaModel)} {
        }

        const std::shared_ptr<Utilities::Shaders::ShaderUtil> ShaderUtil{};;
        const std::shared_ptr<Utilities::GlObjs::VoaModel> VoaModel{};
    };
}
#endif //MIIND_RENDERMODEL_H
