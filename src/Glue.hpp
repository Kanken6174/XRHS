#include "../Dependencies/KronUI/src/topLevelInclude.hpp"
#include "../Dependencies/AHRS_core/src/topLevelManager.hpp"

class OpencvToVideoFrame {
public:
static void updateFromNode(std::shared_ptr<VideoFrame> videoFrame, PipelineNode* node) {
    cv::UMat umat = node->getOutput();

    // Convert the UMat object to a Mat object. This will copy the data if the UMat object is not currently mapped to the CPU.
    cv::Mat mat = umat.getMat(cv::ACCESS_READ);

    // Check if the dimensions have changed
    if (mat.cols != videoFrame->width || mat.rows != videoFrame->height) {
        // Update the texture size
        videoFrame->width = mat.cols;
        videoFrame->height = mat.rows;
        glBindTexture(GL_TEXTURE_2D, videoFrame->getTextureID());
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, videoFrame->width, videoFrame->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    }

    // Check that the Mat object's data can be used as is. This assumes that the Mat object is continuous and in BGR format.
    if (mat.empty()) {
        std::cout << "Nothing to be drawn!\n";
        return;
    }

    if (mat.isContinuous() && mat.type() == CV_8UC3) {
        cv::Mat temp;
        cv::cvtColor(mat, temp, cv::COLOR_BGR2RGBA);
        videoFrame->updateFrame(temp.data);
    } else {
        // If the Mat object's data can't be used as is, convert/copy it to a new Mat object that can be.
        cv::Mat temp;
        cv::cvtColor(mat, temp, cv::COLOR_BGR2RGBA);
        videoFrame->updateFrame(temp.data);
    }
}

    static void updateFromNodeWithTransparency(std::shared_ptr<VideoFrame> videoFrame, PipelineNode* node) {
        cv::UMat umat = node->getOutput();

        // Convert the UMat object to a Mat object. This will copy the data if the UMat object is not currently mapped to the CPU.
        cv::Mat mat = umat.getMat(cv::ACCESS_READ);

        // Check if the dimensions have changed
        if (mat.cols != videoFrame->width || mat.rows != videoFrame->height) {
            // Update the texture size
            videoFrame->width = mat.cols;
            videoFrame->height = mat.rows;
            glBindTexture(GL_TEXTURE_2D, videoFrame->getTextureID());
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, videoFrame->width, videoFrame->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        }

        // Convert mat to a new mat with alpha
        cv::Mat matWithAlpha;
        cv::cvtColor(mat, matWithAlpha, cv::COLOR_BGR2BGRA);

        // Iterate over the pixels and set alpha value
        for(int y = 0; y < matWithAlpha.rows; ++y) {
            for(int x = 0; x < matWithAlpha.cols; ++x) {
                cv::Vec4b& pixel = matWithAlpha.at<cv::Vec4b>(y, x);

                // If pixel is black, make it fully transparent
                if (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0)
                    pixel[3] = 0;
                else
                    pixel[3] = 255;
            }
        }

        // Update the frame with the new mat data
        videoFrame->updateFrame(matWithAlpha.data);
    }
};
