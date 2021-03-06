#pragma once

#include <armadillo>

static double charge = 1.0;
static double mass = 40.078;
static double B_0 = 1 * 9.65e1;
static double V_0 = 0.0025 * 9.65e7;
static double d = 500;
static double step_size = 1e-3;
static int N = 100000;
static double f = 2.0;
static double omega_V = 6.0;

static arma::vec pos = { 100.0, 0.0, 100.0 };
static arma::vec vel = { 0.0, 1.0, 0.0 };
