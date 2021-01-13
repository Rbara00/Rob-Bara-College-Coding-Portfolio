function varargout = myFFT2(varargin)
%
%  myFFT2(im) performs FFT2 and plots the result
%
%   Iyad Obeid
%   7 November 2017
%   added optional output variables
%
%   Originally created:
%   5 April 2016

flag = 'db';
if nargin >= 1
    im = varargin{1};
end
if nargin >= 2
    flag = varargin{2};
    if (~strcmpi(flag,'linear') && ~strcmpi(flag,'db'))
        error('flag not understood');
    end
end
nPts = 512;
if nargin >= 3
    nPts = varargin{3};
end

Y = fft2(im,nPts,nPts);
f1 = linspace(-1,1,nPts);
f2 = linspace(-1,1,nPts);

[f1,f2] = meshgrid(f1,f2);
if strcmp(flag,'linear')
    surf(f1,f2,abs(fftshift(Y)),'LineStyle','none');
    zlabel('magnitude');
else
    surf(f1,f2,db(fftshift(Y)),'LineStyle','none');
    zlabel('decibels');
end

xlabel('x-frequencies (rads/sample)'); ylabel('y-frequencies (rads/sample)');
rotate3d on

xlim([0 1]);
ylim([0 1]);

if nargout >= 1
    varargout{1} = fftshift(Y);
end

if nargout >= 2
    varargout{2} = f1;
end

if nargout >= 3
    varargout{3} = f2;
end