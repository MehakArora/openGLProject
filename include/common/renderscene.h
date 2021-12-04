//
// Created by mehak on 12/4/2021.
//

#ifndef OPENGLPROJECT_RENDERSCENE_H
#define OPENGLPROJECT_RENDERSCENE_H


void drawSphere(glm::vec3 pos,
                const GLuint &programID,
                const GLuint &LightID,
                const GLuint &ViewMatrixID,
                const GLuint &MatrixID,
                const GLuint &ModelMatrixID,
                const GLuint &vertexbuffer,
                const GLuint &normalbuffer,
                const GLuint &uvbuffer,
                const GLuint &elementbuffer,
                std::vector<unsigned short> indices);

void renderASuzie(glm::vec3 pos,
                  const GLuint &programID,
                  const GLuint &LightID,
                  const GLuint &ViewMatrixID,
                  const GLuint &MatrixID,
                  const GLuint &ModelMatrixID,
                  const GLuint &Texture,
                  const GLuint &TextureID,
                  const GLuint &vertexbuffer,
                  const GLuint &normalbuffer,
                  const GLuint &uvbuffer,
                  const GLuint &elementbuffer,
                  std::vector<unsigned short> indices);


void renderFootballField( const GLuint &programID,
                          const GLuint &LightID,
                          const GLuint &ViewMatrixID,
                          const GLuint &MatrixID,
                          const GLuint &ModelMatrixID,
                          const GLuint &Texture,
                          const GLuint &TextureID,
                          const GLuint &vertexbuffer,
                          const GLuint &normalbuffer,
                          const GLuint &uvbuffer,
                          const GLuint &elementbuffer,
                          std::vector<unsigned short> indices);


#endif //OPENGLPROJECT_RENDERSCENE_H
