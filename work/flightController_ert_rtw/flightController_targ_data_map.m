    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (flightController_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightController_P.SRFlipFlop_initial_condition
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 29;
            section.data(29)  = dumData; %prealloc

                    ;% flightController_P.takeoff_gain_Gain
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% flightController_P.D_z_Gain
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% flightController_P.P_z_Gain
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% flightController_P.SaturationThrust_UpperSat
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% flightController_P.SaturationThrust_LowerSat
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% flightController_P.Constant1_Value
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% flightController_P.D_xy_Gain
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% flightController_P.Gain_Gain
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 8;

                    ;% flightController_P.Saturation_UpperSat
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 9;

                    ;% flightController_P.Saturation_LowerSat
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 10;

                    ;% flightController_P.P_xy_Gain
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 11;

                    ;% flightController_P.TorqueTotalThrustToThrustPerMotor_Value
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 13;

                    ;% flightController_P.w0_Value
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 29;

                    ;% flightController_P.P_yaw_Gain
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 30;

                    ;% flightController_P.D_yaw_Gain
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 31;

                    ;% flightController_P.P_pr_Gain
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 32;

                    ;% flightController_P.DiscreteTimeIntegrator_gainval
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 34;

                    ;% flightController_P.DiscreteTimeIntegrator_IC
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 35;

                    ;% flightController_P.DiscreteTimeIntegrator_UpperSat
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 36;

                    ;% flightController_P.DiscreteTimeIntegrator_LowerSat
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 37;

                    ;% flightController_P.I_pr_Gain
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 38;

                    ;% flightController_P.D_pr_Gain
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 39;

                    ;% flightController_P.Constant_Value
                    section.data(23).logicalSrcIdx = 23;
                    section.data(23).dtTransOffset = 41;

                    ;% flightController_P.ThrustToMotorCommand_Gain
                    section.data(24).logicalSrcIdx = 24;
                    section.data(24).dtTransOffset = 42;

                    ;% flightController_P.Saturation5_UpperSat
                    section.data(25).logicalSrcIdx = 25;
                    section.data(25).dtTransOffset = 43;

                    ;% flightController_P.Saturation5_LowerSat
                    section.data(26).logicalSrcIdx = 26;
                    section.data(26).dtTransOffset = 44;

                    ;% flightController_P.MotorDirections_Gain
                    section.data(27).logicalSrcIdx = 27;
                    section.data(27).dtTransOffset = 45;

                    ;% flightController_P.Delay_InitialCondition
                    section.data(28).logicalSrcIdx = 28;
                    section.data(28).dtTransOffset = 49;

                    ;% flightController_P.antiWU_Gain_Gain
                    section.data(29).logicalSrcIdx = 29;
                    section.data(29).dtTransOffset = 50;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightController_P.Logic_table
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 0;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (flightController_B)
        ;%

            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (flightController_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightController_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% flightController_DW.Delay_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightController_DW.Memory_PreviousInput
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4194718196;
    targMap.checksum1 = 1061061113;
    targMap.checksum2 = 3971671900;
    targMap.checksum3 = 690645091;

