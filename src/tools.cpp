#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  // RMSE = sqrt(sum((estimation - ground_truth)^2) / len(estimations)).
  // First, compute the sum of square difference.
  VectorXd square_diff = VectorXd(4);
  square_diff.fill(0);
  for (int i = 0; i < estimations.size(); ++i) {
    VectorXd estimation = estimations[i];
    VectorXd truth = ground_truth[i];
    for (int j = 0; j < square_diff.size(); ++j) {
      square_diff[j] += pow(estimation[j] - truth[j], 2);
    }
  }
  // Then, compute RMSE.
  VectorXd rmse = VectorXd(4);
  for (int j = 0; j < square_diff.size(); ++j) {
    rmse[j] = sqrt(square_diff[j] / estimations.size());
  }
  return rmse;
}
