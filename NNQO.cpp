iteration = 0;
do {
    newrdotSum.Reset();
    for (int n = 0; n < NumN; n++) {
      SumAw.Reset();
      for (int i = 0; i < NumN; i++) {
        SumAw.Add(A[n * NumN + i] * w[i]);
      }
      r[n] = b[n] - SumAw.Sum();
      if ((w[n] < 1e-10) && (r[n] < 0.0)) r[n] = 0.0;
      newrdotSum.Add(r[n] * r[n]);
    }
    
    SumStepSizeNumer = newrdotSum.Sum();
    
    rArdotSum.Reset();
    for (int n = 0; n < NumN; n++) {
      SumAr.Reset();
      for (int i = 0; i < NumN; i++) {
        SumAr.Add(A[n * NumN + i] * r[i]);
      }
      rArdotSum.Add(r[n] * SumAr.Sum());
    }
    SumStepSizeDenom = rArdotSum.Sum();
    
    StepSize = SumStepSizeNumer / SumStepSizeDenom;
    
    if (isnan(StepSize)) StepSize = 0.001;
    
    for (int n = 0; n < NumN; n++) {
      if (r[n] < 0.0) StepSize = min(abs(StepSize), abs(w[n] / r[n])) * StepSize / abs(StepSize);
    }
    
    for (int n = 0; n < NumN; n++) {
      w[n] = w[n] + StepSize * r[n];
      if (w[n] < 1e-10) w[n] = 0.0;
    }
    
    rdot = SumStepSizeNumer;
    
    if (rdot > (20.0 * (double)NumN) || isnan(rdot) || (iteration > 5000)) {
      // do something in case of divergence
    }
} while (rdot > 0.00005);